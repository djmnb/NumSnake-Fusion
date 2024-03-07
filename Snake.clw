; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSnakeView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Snake.h"
LastPage=0

ClassCount=6
Class1=CSnakeApp
Class2=CSnakeDoc
Class3=CSnakeView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Class5=CAboutDlg
Resource2=IDR_MAINFRAME
Class6=CMdlg
Resource3=IDD_DIALOG1

[CLS:CSnakeApp]
Type=0
HeaderFile=Snake.h
ImplementationFile=Snake.cpp
Filter=N

[CLS:CSnakeDoc]
Type=0
HeaderFile=SnakeDoc.h
ImplementationFile=SnakeDoc.cpp
Filter=N

[CLS:CSnakeView]
Type=0
HeaderFile=SnakeView.h
ImplementationFile=SnakeView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=CSnakeView


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T




[CLS:CAboutDlg]
Type=0
HeaderFile=Snake.cpp
ImplementationFile=Snake.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_APP_ABOUT
CommandCount=14

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_DIALOG1]
Type=1
Class=CMdlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631620

[CLS:CMdlg]
Type=0
HeaderFile=Mdlg.h
ImplementationFile=Mdlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CMdlg
VirtualFilter=dWC

