from __future__ import print_function
import os
import io
import time
from googleapiclient.discovery import build
from googleapiclient.http import MediaFileUpload, MediaIoBaseDownload
from httplib2 import Http
from oauth2client import file, client, tools
import subprocess


# 權限必須
SCOPES = ['https://spreadsheets.google.com/feeds', 'https://www.googleapis.com/auth/drive']


def delete_drive_service_file(service, file_id):
    service.files().delete(fileId=file_id).execute()


def update_file(service, update_drive_service_name, local_file_path):
    """
    將本地端的檔案傳到雲端上
    :param service: 認證用
    :param update_drive_service_name: 存到 雲端上的名稱
    :param local_file_path: 本地端的位置
    :param local_file_name: 本地端的檔案名稱
    """

    print("Uploading file...")
    file_metadata = {'name': update_drive_service_name}
    media = MediaFileUpload(local_file_path, )
    file_metadata_size = media.size()
    start = time.time()
    file_id = service.files().create(body=file_metadata, media_body=media, fields='id').execute()
    end = time.time()
    print("Upload Successful!")
    print('Cloud File Name: ' + str(file_metadata['name']))
    print('Cloud File ID: ' + str(file_id['id']))
    print('File Size: ' + str(file_metadata_size) + ' byte')
    print("Upload Time: " + str(end - start))

    return file_metadata['name'], file_id['id']


def search_file(service, update_drive_service_name, is_delete_search_file=False):
    """
    本地端
    取得到雲端名稱，可透過下載時，取得file id 下載
    :param service: 認證用
    :param update_drive_service_name: 要上傳到雲端的名稱
    :param is_delete_search_file: 判斷是否需要刪除這個檔案名稱
    """

    # Call the Drive v3 API
    results = service.files().list(fields="nextPageToken, files(id, name)", spaces='drive',
                                   q="name = '" + update_drive_service_name + "' and trashed = false",
                                   ).execute()

    items = results.get('files', [])
    if not items:
        print('Did not find ' + update_drive_service_name + ' .')
    else:
        print('Searching: ')
        for item in items:
            times = 1
            print(u'{0} ({1})'.format(item['name'], item['id']))
            if is_delete_search_file is True:
                print("Deleted file is :" + u'{0} ({1})'.format(item['name'], item['id']))
                delete_drive_service_file(service, file_id=item['id'])

            if times == len(items):
                return item['id']
            else:
                times += 1


def trashed_file(service, is_delete_trashed_file=False):
    """
    抓取到雲端上垃圾桶內的全部檔案，進行刪除
    :param service: 認證用
    :param is_delete_trashed_file: 是否要刪除垃圾桶資料
    """

    results = service.files().list(fields="nextPageToken, files(id, name)", spaces='drive', q="trashed = true",
                                   ).execute()
    items = results.get('files', [])
    if not items:
        print('Trash can has no data.')
    else:
        print('Trash can: ')

        for item in items:
            print(u'{0} ({1})'.format(item['name'], item['id']))
            if is_delete_trashed_file is True:
                print("Delete file is:" + u'{0} ({1})'.format(item['name'], item['id']))
                delete_drive_service_file(service, file_id=item['id'])


def main(is_update_file_function=False, update_drive_service_name=None, update_file_path=None):
    """
    :param is_update_file_function: 判斷是否執行上傳的功能
    :param update_drive_service_name: 要上傳到雲端上的檔案名稱
    :param update_file_path: 要上傳檔案的位置以及名稱
    """

    print("is_update_file_function")
    print(type(is_update_file_function))
    print(is_update_file_function)

    store = file.Storage('token.json')
    creds = store.get()

    if not creds or creds.invalid:
        flow = client.flow_from_clientsecrets('credentials.json', SCOPES)
        creds = tools.run_flow(flow, store)

    service = build('drive', 'v3', http=creds.authorize(Http()))
    print('*' * 10)

    def download():
        # Use a breakpoint in the code line below to debug your script.
        file_id = '0BwwA4oUTeiV1UVNwOHItT0xfa2M'
        request = service.files().get_media(fileId=file_id)
        fh = io.BytesIO()
        downloader = MediaIoBaseDownload(fh, request)
        done = False
        while done is False:
            status, done = downloader.next_chunk()
            print
            "Download %d%%." % int(status.progress() * 100)
    if is_update_file_function is True:
        print(update_file_path + update_drive_service_name)
        print("=====Processing Uploading=====")

        # 清空 雲端垃圾桶檔案
        # trashed_file(service=service, is_delete_trashed_file=True)

        # 搜尋要上傳的檔案名稱是否有在雲端上並且刪除
        search_file(service=service, update_drive_service_name=update_drive_service_name,
                    is_delete_search_file=True)

        # 檔案上傳到雲端上
        update_file(service=service, update_drive_service_name=update_drive_service_name,
                    local_file_path=os.getcwd() + '/' + update_drive_service_name)

        print("=====Upload finish=====")


if __name__ == '__main__':
    main(is_update_file_function=bool(True), update_drive_service_name='video.mp4', update_file_path=os.getcwd() + '/')