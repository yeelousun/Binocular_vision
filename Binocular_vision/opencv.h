//opencv 使用的头文件
#pragma once
//棋盘图 栅格图
#include "stdafx.h"
#include"cv.h"
#include"highgui.h"
#define numx_qipan 10
#define numy_qipan 8
//单标定
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <stdio.h>
#include <string.h>
#include <time.h>
//立体标定
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//小波变换
#include "iostream"
#include "cv.h"
#include "highgui.h"
#include "math.h" 
//去除背景
#include <iostream>
#include <string.h>
#include <cxcore.h>
#include <cv.h>
#include <highgui.h>
#include <fstream>
//#include "legacy.hpp"
//点云合成
#include "stdafx.h"
#include "iostream"
#include "highgui.h"
#include <cv.h> 
#include <cxcore.h>
#include "math.h" 
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/core.hpp>



#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include <ctime>

#define M_PI       3.14159265358979323846


//using namespace cv;
using namespace std;
int _convert = 0;
UINT _acp = ATL::_AtlGetConversionACP(); 
LPCWSTR _lpw = NULL;
LPCSTR _lpa = NULL;