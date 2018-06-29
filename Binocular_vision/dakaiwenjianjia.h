#pragma once
#include "Binocular_vision.h"
#include "Binocular_visionDlg.h"
#include "afxdialogex.h"
static bool   ListFolder(vector<string>& l) 
{ 	
CFileDialog   Dlg(TRUE,NULL,NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT|OFN_ALLOWMULTISELECT); 
Dlg.m_ofn.lpstrFile   =   new TCHAR[6000];
memset(Dlg.m_ofn.lpstrFile,0,6000);  // 初始化定义的缓冲
Dlg.m_ofn.nMaxFile = 6000;           // 重定义 nMaxFile 

if(Dlg.DoModal()==IDOK) 
   { 
	    CString  FileName; 
        POSITION   pos   =   Dlg.GetStartPosition(); 
        while(pos) 
        { 
			CString   szFileName   =   Dlg.GetNextPathName(pos); 
			
            //AfxMessageBox(szFileName); 
			FileName+=szFileName+_T("\r\n");
			
			l.push_back(T2A(szFileName.GetBuffer()));
        } 
		AfxMessageBox(FileName); 
		return true;
   }
        else
        return false;

        delete [] Dlg.m_ofn.lpstrFile;   
   
}