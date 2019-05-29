#ifndef _FIREVIDEO_H_
#define _FIREVIDEO_H_

#include <QtGui>
#include <QtWidgets/qwidget.h>
#include <qwidgetresizehandler_p.h>
#include <qsize.h>
#include <qlabel.h>
//#include <qframe.h> 
#include <qevent.h>
#include <qpainter.h>
#include <qmediaplayer.h>
#include <QMediaPlaylist>
#include <MyVideoWidget.h> 
#include <QTimer>   //��ʱ��
#include <qtextcodec.h>
#include "NoFocusDelegate.h"
#include "FireSlider.h"
#include "FireButton.h"
class FireVideo :public QWidget
{
	Q_OBJECT
	friend class FullScreenWidget;
public:
	explicit FireVideo(QWidget *parent = 0);
	~FireVideo();
	private slots :
	//buttons click slots
	void BtnOpenFile_Click();
	void BtnPlay_Click();
	void BtnPause_Click();
	void BtnCease_Click();
	void BtnNext_Click();
	void BtnLast_Click();
	void BtnVoice_Click();
	void BtnFullScreen_Click();
	void BtnExitFullScreen_Click();
	void BtnHideAll_Click();
	void BtnDeleteCur_Click();//ɾ��Ŀ¼�б���ѡ�е���Ƶ
	void BtnDeleteAll_Click();//ɾ���б������е���Ƶ
	void BtnPlayCur_Click();//����Ŀ¼�б���ѡ�е���Ƶ
	void BtnNextPlay_Click();//��Ŀ¼�б���ѡ�е���Ƶ��Ϊ��һ�������ŵ���Ƶ
	void BtnRestore_Click();//��ԭĬ�ϴ���
	void Updata_PlaySlider_Duration(qint64 duration);
	void Updata_PlaySlider_Position(qint64 pos);
	void MTimeSlot();
	int Get_Video_Position();
	void Set_Video_Volume(int vol);
	//״̬���²ۺ���
	void PlayStateChange(QMediaPlayer::State state);
	void playlistTable_DoubleClicked(QTableWidgetItem* item);
	void Fire_Media_Changed(const QMediaContent &);
	void videoWidget_ContextMenu(const QPoint& pos);
	void playlistTable_ContextMenu(const QPoint& pos);
	void playlistTable_Drafting(QTableWidgetItem *currentItem);
private:
	void FireVideo_Init_UI();
	void FireVideo_Init_Player();
	void FireVideo_Init_Table();
	void FireVideo_Init_InterfaceLevel();
	void FireVideo_Init_Connect();
	void Fire_Add_VideoList(QString& file);
	void Fire_Write_VideoList(); //����Ƶ�ļ�д���ļ���
	void Fire_Read_VideoList(); //��������ʱ��ȡ�ϴ��˴δ洢��Ƶ������ʼ�������б�
	QString CalVideoPlayTime(); //������Ƶ�ļ���Ҫ���ŵ���ʱ��
	QString CalVideoCurPlayTime(); //������Ƶ��ǰ����ʱ��
	void Fire_ListTable_color(); //�����б�����ɫ����
	//Event
	void paintEvent(QPaintEvent *event);
	void keyPressEvent(QKeyEvent* event);
	//void enterEvent(QEvent *event); //�������¼�,���밴��λ��,��ʾ����
	//void mousePressEvent(QMouseEvent* event); 
	void wheelEvent(QWheelEvent*event); //������
	void contextMenuEvent(QContextMenuEvent *event);
	void dragEnterEvent(QDragEnterEvent *event);//��ק�¼�
	void dropEvent(QDropEvent *event);//�ͷ�����¼�
private:
	//buttons
	FireButton* BtnMinimize;
	FireButton* BtnExit;
	FireButton* BtnOpenFile;
	FireButton* BtnPlay;
	FireButton* BtnPause;
	FireButton* BtnCease;
	FireButton* BtnNext;
	FireButton* BtnLast;
	FireButton* BtnVoice;
	FireButton* BtnFullScreen;
	FireButton* BtnHideAllKeys;//�������а���
	//��Ļlabels
	QLabel* VideoInfoLable; //��ʾ���ڲ�����Ƶ�ļ���Ϣ
	QLabel* VolValue;      //������С
	QLabel* PlaySchedule; //ʵʱ���Ž���ʱ��
	QLabel* PlaySumSchedule;//��Ƶ��ʱ��
	QLabel* SystemTime;   //��ʾ��ǰϵͳʱ��
	//������ʾlabels
	QLabel* HintLabel_Mini;
	QLabel* HintLabel_Exit;
	QLabel* HintLabel_OpenFile;
	QLabel* HintLabel_Pause;
	QLabel* HintLabel_Play;
	QLabel* HintLabel_Next;
	QLabel* HintLabel_Stop;
	QLabel* HintLabel_Voice;
	//list
	QTableWidget* playlistTable; //��Ƶ�б�
	QStringList VideoListFlies; //�洢��Ƶ�ļ�����·��
	QStringList VideoListName;  //���洢�б��ļ�����Ƶ����
	QStringList VideolistTime; //�洢�б��ļ��Ĳ���ʱ��
	//meuns
	QMenu* VideoWidgetMenu;  //�����ߴ��һ��˵�
	QMenu* FullScreen_VideoWidgetMenu; //ȫ���һ��˵�
	QMenu* Item_VideoListMenu; //ѡ����Ƶʱ�һ��˵�
	QMenu* VideoListMenu;  //δѡ����Ƶ�һ��˵�
	//QActions
	QAction* Play;
	QAction* Pause;
	QAction* Stop;
	QAction* NextVideo;
	QAction* LastVideo;
	QAction* HideAll; //�������д��ڣ�ֻ��ʾ��Ƶ����
	QAction* Restore; //��ԭ����
	QAction* FullScreen;
	QAction* Exit_FullScreen;
	QAction* AddVideo;
	QAction* DeleteCur;
	QAction* DeleteAll;
	QAction* PlayCur;
	QAction* NextPlay; //��ǰ��Ƶ������ֱ�Ӳ��Ÿ���Ƶ
	//time
	QTimer* timer; //��ʱ��
	//Slider
	FireSlider* playSlider;//���Ž�����
	QSlider* volSlider;
	//��Ƶ������
	QMediaPlayer* player;
	QMediaPlaylist* VideoList;
	//��Ƶ����
	MyVideoWidget* VideoWidget;
	int PlayingPosition;
	int CurrentIndex;
};


#endif


