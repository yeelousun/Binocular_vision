# Binocular_vision
*Use grid image to construct point cloud and simple point cloud processing*
(*upgraded version*)
## Introduction  
The program of master's thesis  
[Paper links](http://kns.cnki.net/KCMS/detail/detail.aspx?dbcode=CMFD&dbname=CMFD201401&filename=1014124607.nh&uid=WEEvREcwSlJHSldRa1FhdXNXa0hIUUVEME15TlBXc09aTFUwdXdZcEp4dz0=$9A4hF_YAuvQ5obgVAqNKPCYcEjKensW4ggI8Fm4gTkoUKaID8j8gFw!!&v=MDI0MDc2R3RmTXFKRWJQSVI4ZVgxTHV4WVM3RGgxVDNxVHJXTTFGckNVUkxLZlllUm1GeXpnVUw3S1ZGMjZHcks=)  
The measurement which expresses the geometrical shape, position, gesture, movement and other
information within the scope of the space is called the 3D measurement. The computer has the
ability to obtain 3D information of objects by using the 3D measurement. These information are
widely used, including design and analysis based on physical objects, detection and monitoring the
production process, surveying and mapping of civic architecture and terrains, deformation
monitoring, design of large-scale construction and piping, manufacture of airplane and ship,
construction of road and bridge, electronic display of valuables, preservation of cultural relics,
plastic surgery and virtual reality, etc.  
This paper combined binocular vision system and structured light system together to calculate
point cloud data, image processing, image stereo matching, and point cloud processing as well.  
## Function  
![image](https://raw.githubusercontent.com/yeelousun/Binocular_vision/master/Program_interface.png)   

*1. Preparatory Work*  
- Make chessboard image for calibrating camera  
- Make Binary Gray Code grid image for projection  
- Single camera calibration  
- Dual camera stereo calibration  

*2. Get Point Cloud*   
- Use wavelet transform to remove image noise  
- Use Active Contour Models (Snake) to remove image background
- Compute point cloud data

*3. Point Cloud Processing*
- Display point cloud
- Remove outliers
- Point cloud down-sampling
- Compute mark points in images
- Point cloud registration by mark points and ICP

## Installation
### OS  
~~WIN7~~**WIN10**  
### Install  
~~VS2010~~    **VS2017**  
~~OpenCV 2.14~~   **OpenCV 3.41**  
~~PCL1.6~~ **PCL1.81**
### Modify
> opencv2/legacy/legacy.hpp  

It doesn't exist in OpenCV 3.41 and modify the corresponding function for the new version.  
> sensor_msgs , CvPoint3D64d 

They doesn't exist in PCL 1.81 and modify the corresponding function for the new version.  
> cv::goodFeaturesToTrack, cv::stereoCalibrate  

Function overloading error in the new version.

> cvSnakeImage 

It has been deleted in OpenCV 3.41, and rewrite this function to apply to 3.41 from 2.14
> cvSaveImage, cvShowImage,.. and so on  

Modify part of the code for c++ version
> pcl::visualization::CloudViewer viewer  

Update the point cloud display for the new version
> fopen,localtime,.. and so on  

Fix some functions for the safe version
## Usage  
[Reference video](https://youtu.be/BECs3CPn-_M)  
## Tip
1. The image must be input in a certain order in stereo calibration and compute point cloud data. Please adjust the image name to achieve this sequence: left image1, right image1, left image2, right image2, ...... 
2. It is difficult to succeed at a time in remove background, point cloud computing, and mark point computing. It need to adjust the corresponding maximum minimum value by the console output to obtain ideal results
3. Point cloud registration input in this order: point cloud 1, point cloud 2, mark point 1, mark point 2.
