# Microsoft Developer Studio Project File - Name="Snake" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Snake - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Snake.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Snake.mak" CFG="Snake - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Snake - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "Snake - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Snake - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "Snake - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 winmm.lib Msimg32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Snake - Win32 Release"
# Name "Snake - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\data.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\Mdlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Snake.cpp
# End Source File
# Begin Source File

SOURCE=.\Snake.rc
# End Source File
# Begin Source File

SOURCE=.\SnakeDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\SnakeView.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\data.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\Mdlg.h
# End Source File
# Begin Source File

SOURCE=.\Operator.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Snake.h
# End Source File
# Begin Source File

SOURCE=.\SnakeDoc.h
# End Source File
# Begin Source File

SOURCE=.\SnakeView.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\map\1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\1619667999599..ico
# End Source File
# Begin Source File

SOURCE=.\res\init\2.ico
# End Source File
# Begin Source File

SOURCE=.\res\init\4.ico
# End Source File
# Begin Source File

SOURCE=.\res\init\5.ico
# End Source File
# Begin Source File

SOURCE=.\res\init\6666.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map\as.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map\Background.BMP
# End Source File
# Begin Source File

SOURCE=.\res\snake2\BG.ico
# End Source File
# Begin Source File

SOURCE=.\res\map\bg1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map\bg2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map\bg3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\map\bg4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\bitmap1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\bitmap2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\bitmap21.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\bmp00001.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\bmp00002.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\body1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\body2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\body3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\bt1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\bt2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\btall.bmp
# End Source File
# Begin Source File

SOURCE=.\res\food\food1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\food\food10.bmp
# End Source File
# Begin Source File

SOURCE=.\res\food\food3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\food\food4.bmp
# End Source File
# Begin Source File

SOURCE=.\res\food\food5.bmp
# End Source File
# Begin Source File

SOURCE=.\res\food\food6.bmp
# End Source File
# Begin Source File

SOURCE=.\res\food\food7.bmp
# End Source File
# Begin Source File

SOURCE=.\res\food\food8.bmp
# End Source File
# Begin Source File

SOURCE=.\res\food\food9.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\head1down.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\head1left.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\head1right.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\head1up.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\head2down.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\head2left.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\head2right.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\head3down.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\head3left.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\head3right.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\head3up.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\head6up.bmp
# End Source File
# Begin Source File

SOURCE=.\res\Snake.ico
# End Source File
# Begin Source File

SOURCE=.\res\Snake.rc2
# End Source File
# Begin Source File

SOURCE=.\res\SnakeDoc.ico
# End Source File
# Begin Source File

SOURCE=.\res\start.bmp
# End Source File
# Begin Source File

SOURCE=.\res\start1.bmp
# End Source File
# Begin Source File

SOURCE=.\res\start2.bmp
# End Source File
# Begin Source File

SOURCE=.\res\start3.bmp
# End Source File
# Begin Source File

SOURCE=.\res\snake2\startbt.bmp
# End Source File
# Begin Source File

SOURCE=".\res\map\背景.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\snake2\角色下.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\snake2\角色下2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\snake2\角色右.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\snake2\角色右2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\snake2\角色左.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\snake2\角色左2.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\snake2\身体.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\snake2\身体1.bmp"
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
