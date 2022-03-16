#! /bin/bash

version="0.2"
cp /content/drive/MyDrive/VideoPoseVideos/video.mp4 /content/videos/video.mp4
python detectron/tools/infer_video.py \
    --cfg detectron/configs/12_2017_baselines/e2e_keypoint_rcnn_R-101-FPN_s1x.yaml \
    --output-dir output \
    --image-ext mp4 \
    --wts https://dl.fbaipublicfiles.com/detectron/37698009/12_2017_baselines/e2e_keypoint_rcnn_R-101-FPN_s1x.yaml.08_45_57.YkrJgP6O/output/train/keypoints_coco_2014_train:keypoints_coco_2014_valminusminival/generalized_rcnn/model_final.pkl \
   videos

cp output/video.mp4.npz VideoPose3D/data/detectronoutput/video.mp4.npz

cd VideoPose3D/data
pwd

python prepare_data_2d_custom.py -i detectronoutput -o myvideos

cd ../../
pwd

cp ./videos/video.mp4 VideoPose3D/video.mp4

cd VideoPose3D

python run.py -d custom -k myvideos -arc 3,3,3,3,3 -c checkpoint --evaluate pretrained_h36m_detectron_coco.bin --render --viz-subject video.mp4 --viz-action custom --viz-camera 0 --viz-video video.mp4 --viz-output output.mp4 --viz-export outputfile --viz-size 6

cp output.mp4 /content/drive/MyDrive/VideoPoseVideos