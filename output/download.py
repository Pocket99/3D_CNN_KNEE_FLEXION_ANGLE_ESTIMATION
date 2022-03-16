from __future__ import print_function
import os
import io
import time
from googleapiclient.discovery import build
from googleapiclient.http import MediaFileUpload, MediaIoBaseDownload
from httplib2 import Http
from oauth2client import file, client, tools
import shutil
import subprocess


# 權限必須
SCOPES = ['https://spreadsheets.google.com/feeds', 'https://www.googleapis.com/auth/drive']
def search_file(service, file_name):
    """
    本地端
    取得到雲端名稱，可透過下載時，取得file id 下載
    :param service: 認證用
    :param update_drive_service_name: 要上傳到雲端的名稱
    :param is_delete_search_file: 判斷是否需要刪除這個檔案名稱
    """

    # Call the Drive v3 API
    results = service.files().list(fields="nextPageToken, files(id, name)", spaces='drive',
                                   q="name = '" + file_name + "' and trashed = false",
                                   ).execute()

    items = results.get('files', [])
    if not items:
        print('Did not find ' + file_name + ' .')
    else:
        print('Searching: ')
        for item in items:
            times = 1
            print(u'{0} ({1})'.format(item['name'], item['id']))
            return item['id']

def main(is_update_file_function=False):
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

    # Use a breakpoint in the code line below to debug your script.
    def downloadVideo():
        file_id = search_file(service,'output.mp4')
        request = service.files().get_media(fileId=file_id)
        fh = io.BytesIO()
        downloader = MediaIoBaseDownload(fh, request)
        done = False
        while done is False:
            status, done = downloader.next_chunk()
            print("Download %d%%." % int(status.progress() * 100))
        fh.seek(0)
        with open('D:/490Qt/output/output.mp4', 'wb') as f:
            shutil.copyfileobj(fh, f, length=131072)
        service.files().delete(fileId=file_id).execute()
#find txt
    def downloadTxt():
        file_id = search_file(service, 'angle.txt')
        request = service.files().get_media(fileId=file_id)
        fh = io.BytesIO()
        downloader = MediaIoBaseDownload(fh, request)
        done = False
        while done is False:
            status, done = downloader.next_chunk()
            print("Download %d%%." % int(status.progress() * 100))
        fh.seek(0)
        with open('D:/490Qt/output/angle.txt', 'wb') as f:
            shutil.copyfileobj(fh, f, length=131072)
        service.files().delete(fileId=file_id).execute()


    downloadVideo()
    downloadTxt()

if __name__ == '__main__':
    main(is_update_file_function=bool(True))