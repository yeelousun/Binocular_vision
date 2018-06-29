#pragma once
#include <iostream>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/filters/voxel_grid.h>

int
dianyunxiacaiyang (const char* filename,float m)
{
	pcl::PCLPointCloud2::Ptr cloud (new pcl::PCLPointCloud2());
	pcl::PCLPointCloud2::Ptr cloud_filtered (new pcl::PCLPointCloud2());

  // Fill in the cloud data
  pcl::PCDReader reader;
  // Replace the path below with the path where you saved your file
  reader.read (filename, *cloud); // Remember to download the file first!

  std::cerr << "PointCloud before filtering: " << cloud->width * cloud->height 
       << " data points (" << pcl::getFieldsList (*cloud) << ").";

  // Create the filtering object
  pcl::VoxelGrid<pcl::PCLPointCloud2> sor;
  sor.setInputCloud (cloud);
  sor.setLeafSize (m, m, m);
  sor.filter (*cloud_filtered);

  std::cerr << "PointCloud after filtering: " << cloud_filtered->width * cloud_filtered->height 
       << " data points (" << pcl::getFieldsList (*cloud_filtered) << ").";

  pcl::PCDWriter writer;
     
  char  filename1[1000];
  std::string s = filename;
  int index=(int)s.find_first_of(".");
  s =s.substr(0,index);
  sprintf_s(filename1,1000,"%s_d.pcd", s.c_str());
  writer.write (filename1, *cloud_filtered, 
         Eigen::Vector4f::Zero (), Eigen::Quaternionf::Identity (), false);
  return 1;
}