#pragma once
#include <iostream>
#include <fstream>
#include <math.h>
#include <malloc.h> 
#include <iomanip>

#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>

using namespace std; 
using std::string;
using std::ofstream;
using std::ifstream;

double cc[5000][3];

bool Gauss(double A[][3], double B[][3], int n)
{
    int k;
    double max, temp;
    double t[3][3];                //临时矩阵
    //将A矩阵存放在临时矩阵t[n][n]中
    for (int i = 0; i < n; i++)        
    {
        for (int j = 0; j < n; j++)
        {
            t[i][j] = A[i][j];
        }
    }
    //初始化B矩阵为单位阵
    for (int i = 0; i < n; i++)        
    {
        for (int j = 0; j < n; j++)
        {
            B[i][j] = (i == j) ? (double)1 : 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        //寻找主元
        max = t[i][i];
        k = i;
        for (int j = i+1; j < n; j++)
        {
            if (fabs(t[j][i]) > fabs(max))
            {
                max = t[j][i];
                k = j;
            }
        }
        //如果主元所在行不是第i行，进行行交换
        if (k != i)
        {
            for (int j = 0; j < n; j++)
            {
                temp = t[i][j];
                t[i][j] = t[k][j];
                t[k][j] = temp;
                //B伴随交换
                temp = B[i][j];
                B[i][j] = B[k][j];
                B[k][j] = temp; 
            }
        }
        //判断主元是否为0, 若是, 则矩阵A不是满秩矩阵,不存在逆矩阵
        if (t[i][i] == 0)
        {
            cout << "There is no inverse matrix!";
            return false;
        }
        //消去A的第i列除去i行以外的各行元素
        temp = t[i][i];
        for (int j = 0; j < n; j++)
        {
            t[i][j] = t[i][j] / temp;        //主对角线上的元素变为1
            B[i][j] = B[i][j] / temp;        //伴随计算
        }
        for (int j = 0; j < n; j++)        //第0行->第n行
        {
            if (j != i)                //不是第i行
            {
                temp = t[j][i];
                for (int k = 0; k < n; k++)        //第j行元素 - i行元素*j列i行元素
                {
                    t[j][k] = t[j][k] - t[i][k]*temp;
                    B[j][k] = B[j][k] - B[i][k]*temp;
                }
            }
        }
    }
    return true;
}
int dianyunpeidui(vector<string> imagelist,CString filename)
{
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in2 (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out2 (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_outz (new pcl::PointCloud<pcl::PointXYZ>);
  pcl::io::loadPCDFile<pcl::PointXYZ> (imagelist[2], *cloud_in);
  pcl::io::loadPCDFile<pcl::PointXYZ> (imagelist[3], *cloud_out);
  pcl::io::loadPCDFile<pcl::PointXYZ> (imagelist[0], *cloud_outz);
  pcl::io::loadPCDFile<pcl::PointXYZ> (imagelist[1], *cloud_in2);
  pcl::io::loadPCDFile<pcl::PointXYZ> (imagelist[0], *cloud_out2);
  for (size_t i = 0; i < cloud_outz->points.size (); ++i)
  {
	cc[i][0] = cloud_outz->points[i].x ;
	cc[i][1] = cloud_outz->points[i].y ;
	cc[i][2] = cloud_outz->points[i].z ;
  }
  double a[3][3]={0},b[3][3]={0};
  for (size_t i = 0; i < cloud_out->points.size (); ++i)
  {
    a[i][0] = cloud_in->points[i].x;
    a[i][1] = cloud_in->points[i].y;
    a[i][2] = cloud_in->points[i].z;
	b[i][0] = cloud_out->points[i].x ;
	b[i][1] = cloud_out->points[i].y ;
	b[i][2] = cloud_out->points[i].z ;
  }
  double v1[3]={0},w1[3]={0}, v0[3]={0},w0[3]={0};
 
  for(int i=0;i<3;i++)
  {
	  v1[i]=a[1][i]-a[0][i];
	  w1[i]=b[1][i]-b[0][i];
	  v0[i]=a[2][i]-a[0][i];
	  w0[i]=b[2][i]-b[0][i];
  }
  double v3[3]={0},w3[3]={0};
  v3[0]=v1[1]*v0[2]-v0[1]*v1[2];
  v3[1]=v1[2]*v0[0]-v1[0]*v0[2];
  v3[2]=v1[0]*v0[1]-v0[0]*v1[1];

  w3[0]=w1[1]*w0[2]-w0[1]*w1[2];
  w3[1]=w1[2]*w0[0]-w1[0]*w0[2];
  w3[2]=w1[0]*w0[1]-w0[0]*w1[1];

  double v2[3]={0},w2[3]={0};
 
  v2[0]=v3[1]*v1[2]-v1[1]*v3[2];
  v2[1]=v3[2]*v1[0]-v3[0]*v1[2];
  v2[2]=v3[0]*v1[1]-v1[0]*v3[1];

  w2[0]=w3[1]*w1[2]-w1[1]*w3[2];
  w2[1]=w3[2]*w1[0]-w3[0]*w1[2];
  w2[2]=w3[0]*w1[1]-w1[0]*w3[1];

  double mov1=0,mov2=0,mov3=0,mow1=0,mow2=0,mow3=0;
  mov1=sqrt(v1[0]*v1[0]+v1[1]*v1[1]+v1[2]*v1[2]);
  mov2=sqrt(v2[0]*v2[0]+v2[1]*v2[1]+v2[2]*v2[2]);
  mov3=sqrt(v3[0]*v3[0]+v3[1]*v3[1]+v3[2]*v3[2]);
  mow1=sqrt(w1[0]*w1[0]+w1[1]*w1[1]+w1[2]*w1[2]);
  mow2=sqrt(w2[0]*w2[0]+w2[1]*w2[1]+w2[2]*w2[2]);
  mow3=sqrt(w3[0]*w3[0]+w3[1]*w3[1]+w3[2]*w3[2]);
  
  for(int i=0;i<3;i++)
  {
	  v1[i]=v1[i]/mov1;
	  v2[i]=v2[i]/mov2;
	  v3[i]=v3[i]/mov3;
	  w1[i]=w1[i]/mow1;
	  w2[i]=w2[i]/mow2;
	  w3[i]=w3[i]/mow3;

  }
  double a1[3][3]={0},b1[3][3]={0},a2[3][3]={0},R[3][3]={0};
   for (int i = 0; i < 3; i++)
    {
    
	 a1[i][0]=v1[i];
	 a1[i][1]=v2[i];
	 a1[i][2]=v3[i];
	 b1[i][0]=w1[i];
	 b1[i][1]=w2[i];
	 b1[i][2]=w3[i];

    }
   Gauss(a1, a2, 3);

   for(int i=0;i<3;i++)   
   {
	   for(int j=0;j<3;j++)
	   {
		   for(int k=0;k<3;k++)
		   {
		   R[i][j]=a2[i][k]*b1[k][j]+R[i][j];
		   }
	   }
   }

   double T[3]={0};
   for(int i=0;i<3;i++)
   {
	   T[i]=b[1][i]-a[1][0]*R[0][i]-a[1][1]*R[1][i]-a[1][2]*R[2][i];
   }

   for (size_t i = 0; i < cloud_outz->points.size (); ++i)
  {

	cloud_outz->points[i].x =cc[i][0]*R[0][0]+cc[i][1]*R[1][0]+cc[i][2]*R[2][0]+T[0];
	cloud_outz->points[i].y =cc[i][0]*R[0][1]+cc[i][1]*R[1][1]+cc[i][2]*R[2][1]+T[1];
	cloud_outz->points[i].z =cc[i][0]*R[0][2]+cc[i][1]*R[1][2]+cc[i][2]*R[2][2]+T[2];
  }
  pcl::io::savePCDFileASCII("test1.pcd", *cloud_in);
  pcl::io::savePCDFileASCII("test2.pcd", *cloud_out);
  pcl::io::savePCDFileASCII("change.pcd", *cloud_outz);

  ///test

  ///end test
  
  return 1;
  }