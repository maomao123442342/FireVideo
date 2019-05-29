#include "FireVideo.h"


FireVideo::FireVideo(QWidget *parent)
{
	FireVideo_Init_UI();
	FireVideo_Init_Player();
	FireVideo_Init_Table();
	FireVideo_Init_InterfaceLevel();
	FireVideo_Init_Connect();
	Fire_Read_VideoList();

}
FireVideo::~FireVideo()
{

}
void FireVideo::FireVideo_Init_UI()
{
	HintLabel_Mini = new QLabel(this);
	HintLabel_Mini->setText(QString::fromLocal8Bit("��С��"));
	HintLabel_Mini->adjustSize();
	HintLabel_Mini->setGeometry(QRect(390, 0, 40, 40));  //λ���밴��λ��һ��
	HintLabel_Mini->setStyleSheet("QLabel{background-color:rgb(255,255,199);border:1px solid #242424;}");
	HintLabel_Mini->setAlignment(Qt::AlignCenter); //���ж��뷽ʽ
	HintLabel_Mini->raise();
	HintLabel_Mini->setVisible(false);

	HintLabel_Exit = new QLabel(this);
	HintLabel_Exit->setText(QString::fromLocal8Bit("�ر�"));
	HintLabel_Exit->adjustSize();
	HintLabel_Exit->setGeometry(QRect(420, 0, 40, 40));  //λ���밴��λ��һ��
	HintLabel_Exit->setStyleSheet("QLabel{background-color:rgb(255,255,199);border:1px solid #242424;}");
	HintLabel_Exit->setAlignment(Qt::AlignCenter); //���ж��뷽ʽ
	HintLabel_Exit->setVisible(false);

	HintLabel_OpenFile = new QLabel(this);
	HintLabel_OpenFile->setText(QString::fromLocal8Bit("���ļ�"));
	HintLabel_OpenFile->setGeometry(QRect(30, 440, 90, 90));  //λ���밴��λ��һ��
	HintLabel_OpenFile->adjustSize();
	HintLabel_OpenFile->setStyleSheet("QLabel{background-color:rgb(255,255,199);border:1px solid #242424;}");
	HintLabel_OpenFile->setAlignment(Qt::AlignCenter); //���ж��뷽ʽ
	HintLabel_OpenFile->setVisible(false);

	HintLabel_Pause = new QLabel(this);
	HintLabel_Pause->setText(QString::fromLocal8Bit("��ͣ"));
	HintLabel_Pause->adjustSize();
	HintLabel_Pause->setGeometry(QRect(100, 440, 40, 40));  //λ���밴��λ��һ��
	HintLabel_Pause->setStyleSheet("QLabel{background-color:rgb(255,255,199);border:1px solid #242424;}");
	HintLabel_Pause->setAlignment(Qt::AlignCenter); //���ж��뷽ʽ
	HintLabel_Pause->setVisible(false);

	HintLabel_Play = new QLabel(this);
	HintLabel_Play->setText(QString::fromLocal8Bit("����"));
	HintLabel_Play->adjustSize();
	HintLabel_Play->setGeometry(QRect(100, 440, 40, 40));  //λ���밴��λ��һ��
	HintLabel_Play->setStyleSheet("QLabel{background-color:rgb(255,255,199);border:1px solid #242424;}");
	HintLabel_Play->setAlignment(Qt::AlignCenter); //���ж��뷽ʽ
	HintLabel_Play->setVisible(false);

	HintLabel_Next = new QLabel(this);
	HintLabel_Next->setText(QString::fromLocal8Bit("��һ��"));
	HintLabel_Next->adjustSize();
	HintLabel_Next->setGeometry(QRect(170, 440, 40, 40));  //λ���밴��λ��һ��
	HintLabel_Next->setStyleSheet("QLabel{background-color:rgb(255,255,199);border:1px solid #242424;}");
	HintLabel_Next->setAlignment(Qt::AlignCenter); //���ж��뷽ʽ
	HintLabel_Next->setVisible(false);

	HintLabel_Stop = new QLabel(this);
	HintLabel_Stop->setText(QString::fromLocal8Bit("ֹͣ"));
	HintLabel_Stop->adjustSize();
	HintLabel_Stop->setGeometry(QRect(240, 440, 40, 40));  //λ���밴��λ��һ��
	HintLabel_Stop->setStyleSheet("QLabel{background-color:rgb(255,255,199);border:1px solid #242424;}");
	HintLabel_Stop->setAlignment(Qt::AlignCenter); //���ж��뷽ʽ
	HintLabel_Stop->setVisible(false);

	HintLabel_Voice = new QLabel(this);
	HintLabel_Voice->setText(QString::fromLocal8Bit("����"));
	HintLabel_Voice->adjustSize();
	HintLabel_Voice->setGeometry(QRect(310, 440, 40, 40));  //λ���밴��λ��һ��
	HintLabel_Voice->setStyleSheet("QLabel{background-color:rgb(255,255,199);border:1px solid #242424;}");
	HintLabel_Voice->setAlignment(Qt::AlignCenter); //���ж��뷽ʽ
	HintLabel_Voice->setVisible(false);


	BtnExit = new FireButton(this);
	BtnExit->setObjectName(QStringLiteral("exitButton"));
	QIcon Exit_Normal, Exit_Focus;
	Exit_Normal.addFile(":/FireVideo/Resources/Exit.png");
	Exit_Focus.addFile(":/FireVideo/Resources/FocusExit.png");
	BtnExit->Input_Button_Icon(Exit_Normal, Exit_Focus); //���ð�ť����ͼ�ꡢ�۽�ͼ��
	BtnExit->Set_HintInfo(HintLabel_Exit);  //���ð�����ʾ��Ϣ
	BtnExit->setIconSize(QSize(30, 30));
	BtnExit->setGeometry(QRect(420, 0, 30, 30));
	BtnExit->setFlat(true);
	BtnExit->setFocusPolicy(Qt::NoFocus);
	BtnExit->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}");

	BtnMinimize = new FireButton(this);
	BtnMinimize->setObjectName(QStringLiteral("Minimize"));
	QIcon Mini_Normal, Mini_Focus;
	Mini_Normal.addFile(":/FireVideo/Resources/Mini.png");
	Mini_Focus.addFile(":/FireVideo/Resources/FocusMini.png");
	BtnMinimize->Input_Button_Icon(Mini_Normal, Mini_Focus);
	BtnMinimize->Set_HintInfo(HintLabel_Mini);
	BtnMinimize->setIconSize(QSize(30, 30));
	BtnMinimize->setGeometry(QRect(390, 0, 30, 30));
	BtnMinimize->setFlat(true);
	BtnMinimize->setFocusPolicy(Qt::NoFocus);
	BtnMinimize->setStyleSheet("QPushButton{background-color:rgba(255,238,144,0);border-style:solid;border-width:0px;border-color:rgba(255,238,144,0);}");

	BtnOpenFile = new FireButton(this);
	BtnOpenFile->setObjectName(QStringLiteral("BtnOpenFile"));
	QIcon OpenFile_Normal;
	OpenFile_Normal.addFile(":/FireVideo/Resources/OpenFile.png");
	BtnOpenFile->Input_Button_Icon(OpenFile_Normal); //���ð���ͼ�꣬����Ĭ�������;۽�Ϊһ��ͼƬ
	BtnOpenFile->Set_HintInfo(HintLabel_OpenFile);
	BtnOpenFile->setFlat(true);
	BtnOpenFile->setIconSize(QSize(35, 35));
	BtnOpenFile->setGeometry(QRect(30, 440, 45, 45));
	BtnOpenFile->setFocusPolicy(Qt::NoFocus);
	BtnOpenFile->setStyleSheet("QPushButton{background-color:rgba(255,238,144,0);border-style:solid;border-width:0px;border-color:rgba(255,238,144,0);}");

	BtnPlay = new FireButton(this);
	BtnPlay->setObjectName(QStringLiteral("BtnPlay"));
	QIcon Play_Normal;
	Play_Normal.addFile(":/FireVideo/Resources/Play.png");
	BtnPlay->Input_Button_Icon(Play_Normal);
	BtnPlay->Set_HintInfo(HintLabel_Play);
	BtnPlay->setFlat(true);
	BtnPlay->setIconSize(QSize(35, 35));
	BtnPlay->setGeometry(QRect(100, 440, 45, 45));
	BtnPlay->setFocusPolicy(Qt::NoFocus);
	BtnPlay->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}");

	BtnPause = new FireButton(this);
	BtnPause->setObjectName(QStringLiteral("BtnPause"));
	QIcon Pause_Normal;
	Pause_Normal.addFile(":/FireVideo/Resources/Pause.png");
	BtnPause->Input_Button_Icon(Pause_Normal);
	BtnPause->Set_HintInfo(HintLabel_Pause);
	BtnPause->setFlat(true);
	BtnPause->setIconSize(QSize(35, 35));
	BtnPause->setGeometry(QRect(100, 440, 45, 45));
	BtnPause->setFocusPolicy(Qt::NoFocus);
	BtnPause->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}");
	BtnPause->setVisible(false);

	BtnCease = new FireButton(this);
	BtnCease->setObjectName(QStringLiteral("BtnCease"));
	QIcon Cease_Normal;
	Cease_Normal.addFile(":/FireVideo/Resources/Stop.png");
	BtnCease->Input_Button_Icon(Cease_Normal);
	BtnCease->Set_HintInfo(HintLabel_Stop);
	BtnCease->setFlat(true);
	BtnCease->setIconSize(QSize(35, 35));
	BtnCease->setGeometry(QRect(240, 440, 45, 45));
	BtnCease->setFocusPolicy(Qt::NoFocus);
	BtnCease->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}");

	BtnNext = new FireButton(this);
	BtnNext->setObjectName(QStringLiteral("BtnNext"));
	QIcon Next_Normal;
	Next_Normal.addFile(":/FireVideo/Resources/Next.png");
	BtnNext->Input_Button_Icon(Next_Normal);
	BtnNext->Set_HintInfo(HintLabel_Next);
	BtnNext->setFlat(true);
	BtnNext->setIconSize(QSize(35, 35));
	BtnNext->setGeometry(QRect(170, 440, 45, 45));
	BtnNext->setFocusPolicy(Qt::NoFocus);
	BtnNext->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}");

	BtnVoice = new FireButton(this);
	BtnVoice->setObjectName(QStringLiteral("BtnVoice"));
	QIcon Voice_Normal;
	Voice_Normal.addFile(":/FireVideo/Resources/Voice.png");
	BtnVoice->Input_Button_Icon(Voice_Normal);
	BtnVoice->Set_HintInfo(HintLabel_Voice);
	BtnVoice->setFlat(true);
	BtnVoice->setIconSize(QSize(35, 35));
	BtnVoice->setGeometry(QRect(310, 440, 45, 45));
	BtnVoice->setFocusPolicy(Qt::NoFocus);
	BtnVoice->setStyleSheet("QPushButton{background-color:rgba(255,255,255,0);border-style:solid;border-width:0px;border-color:rgba(255,255,255,0);}");

	VideoInfoLable = new QLabel(this);
	VideoInfoLable->setGeometry(QRect(5, 0, 380, 30));

	playSlider = new FireSlider(this);
	playSlider->setObjectName(QStringLiteral("playSlider"));
	playSlider->setGeometry(QRect(60, 390, 310, 15));
	playSlider->setOrientation(Qt::Horizontal);
	playSlider->setStyleSheet("QSlider{background-color: black;}\
							    QSlider::sub-page:horizontal{background:red;height:5px;}\
								  QSlider::add-page:horizontal{background:lightgray;height:5px;}\
									QSlider::handle:horizontal{background:blue;width:12px;border:#51b5fb 12px;border-radius:6px;margin:-5px 0px -5px 0px;}\
										background - color: rgb(0, 0, 0);");
	playSlider->setParent(this);
	playSlider->setEnabled(true);
	playSlider->setVisible(false);

	PlaySchedule = new QLabel(this);
	PlaySchedule->setObjectName(QStringLiteral("PlaySchedule"));
	PlaySchedule->setGeometry(QRect(10, 390, 70, 15));
	PlaySchedule->setStyleSheet("background-color: rgb(0,0,0);color:white");
	PlaySchedule->setVisible(false);

	PlaySumSchedule = new QLabel(this);
	PlaySumSchedule->setObjectName(QStringLiteral("PlaySumSchedule"));
	PlaySumSchedule->setGeometry(QRect(390, 390, 70, 15));
	PlaySumSchedule->setStyleSheet("background-color: rgb(0,0,0);color:white");
	PlaySumSchedule->setVisible(false);


	VolValue = new QLabel(this);
	VolValue->setObjectName(QStringLiteral("VolValue"));
	VolValue->setGeometry(QRect(315, 455, 35, 15));
	VolValue->setVisible(false);

	volSlider = new QSlider(this);
	volSlider->setObjectName(QStringLiteral("volSlider"));
	volSlider->setGeometry(QRect(310, 470, 50, 10));
	volSlider->setStyleSheet("QSlider::groove:horizontal{border:0px;height:4px;}"
		"QSlider::sub-page:horizontal{background:#0096ff;}"
		"QSlider::add-page:horizontal{background:lightgray;} "
		"QSlider::handle:horizontal{background:white;width:10px;border:#51b5fb 10px;border-radius:5px;margin:-3px 0px -3px 0px;}");
	volSlider->setRange(0, 100);
	volSlider->setOrientation(Qt::Horizontal);
	volSlider->setEnabled(true);
	volSlider->setVisible(false);

	VideoWidgetMenu = new QMenu(this);
	FullScreen_VideoWidgetMenu = new QMenu(this);
	VideoListMenu = new QMenu(this);
	Item_VideoListMenu = new QMenu(this);
	VideoWidgetMenu->setWindowOpacity(0.8);
	FullScreen_VideoWidgetMenu->setWindowOpacity(0.8);
	VideoListMenu->setWindowOpacity(0.9);
	Item_VideoListMenu->setWindowOpacity(0.9);
	//QActions
	Play = new QAction(QIcon(":/FireVideo/Resources/Play.png"), QString::fromLocal8Bit("����"), this);
	Pause = new QAction(QIcon(":/FireVideo/Resources/Pause.png"), QString::fromLocal8Bit("��ͣ"), this);
	Stop = new QAction(QIcon(":/FireVideo/Resources/Stop.png"), QString::fromLocal8Bit("ֹͣ"), this);
	NextVideo = new QAction(QIcon(":/FireVideo/Resources/Next.png"), QString::fromLocal8Bit("��һ��"), this);
	LastVideo = new QAction(QString::fromLocal8Bit("��һ��"), this);
	HideAll = new QAction(QString::fromLocal8Bit("���ذ���"), this);
	Restore = new QAction(QString::fromLocal8Bit("��ԭ����"), this);
	FullScreen = new QAction(QString::fromLocal8Bit("ȫ��"), this);
	Exit_FullScreen = new QAction(QString::fromLocal8Bit("�˳�ȫ��"), this);;
	AddVideo = new QAction(QString::fromLocal8Bit("�����Ƶ"), this);

	PlayCur = new QAction(QString::fromLocal8Bit("����"), this);
	DeleteCur = new QAction(QString::fromLocal8Bit("�Ƴ�"), this);
	DeleteAll = new QAction(QString::fromLocal8Bit("ȫ���Ƴ�"), this);
	NextPlay = new QAction(QString::fromLocal8Bit("��һ������"), this);

	VideoWidgetMenu->addAction(Play);
	VideoWidgetMenu->addAction(Pause);
	VideoWidgetMenu->addAction(Stop);
	VideoWidgetMenu->addAction(NextVideo);
	VideoWidgetMenu->addAction(LastVideo);
	VideoWidgetMenu->addAction(FullScreen);
	VideoWidgetMenu->addAction(AddVideo);
	VideoWidgetMenu->addAction(HideAll);
	VideoWidgetMenu->addAction(Restore);

	FullScreen_VideoWidgetMenu->addAction(Play);
	FullScreen_VideoWidgetMenu->addAction(Pause);
	FullScreen_VideoWidgetMenu->addAction(Stop);
	FullScreen_VideoWidgetMenu->addAction(NextVideo);
	FullScreen_VideoWidgetMenu->addAction(LastVideo);
	FullScreen_VideoWidgetMenu->addAction(Exit_FullScreen);

	Item_VideoListMenu->addAction(PlayCur);
	Item_VideoListMenu->addAction(DeleteCur);
	Item_VideoListMenu->addAction(DeleteAll);
	Item_VideoListMenu->addAction(NextPlay);

	VideoListMenu->addAction(AddVideo);
	VideoListMenu->addAction(DeleteAll);

	timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(MTimeSlot()));

	this->setWindowTitle("FireVideo");
	this->setWindowFlags(Qt::FramelessWindowHint);
	//�����϶�
	QWidgetResizeHandler *movewin = new QWidgetResizeHandler(this);
	movewin->setMovingEnabled(true);
	this->setWindowOpacity(0.9);
	setAttribute(Qt::WA_TranslucentBackground); //����Ϊ��͸������
	this->setFixedSize(450, 800);//���������ڴ�С�̶��������޸�
	this->setAcceptDrops(true);
}

void FireVideo::FireVideo_Init_Player()
{
	player = new QMediaPlayer(this);
	VideoList = new QMediaPlaylist(this);
	CurrentIndex = -1;
	VideoWidget = new MyVideoWidget(this);
	VideoWidget->setGeometry(0, 30, 450, 400);
	VideoWidget->setFixedSize(450, 400);
	VideoWidget->setContextMenuPolicy(Qt::CustomContextMenu);//�����Ҽ��˵�����
	VideoWidget->setWindowFlags(Qt::FramelessWindowHint);
	VideoWidget->setParent(this);
	setAttribute(Qt::WA_TranslucentBackground, false); //����Ĭ���Ӵ����ǰ�͸��������ʾ
	VideoWidget->setVisible(false);
	VideoWidget->setEnabled(false);
	VideoList->setPlaybackMode(QMediaPlaylist::Sequential); //���β���
	player->setPlaylist(VideoList);
	player->setNotifyInterval(1000);//��Ϣ��������Ϊ1000ms
	player->setVideoOutput(VideoWidget);//������Ƶ��ʾ���
	VideoWidget->SetMediaPlayer(player);//��֤��������������ͬ��
	VideoWidget->SetLabel(PlaySchedule, PlaySumSchedule);
	VideoWidget->SetSlider(playSlider);
	playSlider->SetItPlayer(player);
}

void FireVideo::FireVideo_Init_Table()
{
	playlistTable = new QTableWidget(this);
	playlistTable->setObjectName(QStringLiteral("playlistTable"));
	playlistTable->setGeometry(QRect(10, 495, 430, 295)); //����λ�úʹ�С��������
	playlistTable->setItemDelegate(new NoFocusDelegate());
	playlistTable->setFrameShape(QFrame::NoFrame);
	playlistTable->setColumnCount(1);  //�����б���Ϊһ��
	playlistTable->setFont(QFont("Courier")); //��������
	playlistTable->setSelectionBehavior(QAbstractItemView::SelectRows); //ֻ��ѡ��һ��
	playlistTable->horizontalHeader()->setVisible(false); //����ˮƽ��ͷ
	playlistTable->verticalHeader()->setVisible(false);  //���ش�ֱ��ͷ
	playlistTable->setColumnWidth(0, 450); //����ÿ�г��ȴ�С
	playlistTable->setShowGrid(false); //���طָ���
	playlistTable->setDragEnabled(true);//��Ԫ�������϶�
	playlistTable->setDragDropMode(QTableWidget::DragDropMode::DropOnly);
	playlistTable->setAcceptDrops(true);//������ק���
	playlistTable->setContextMenuPolicy(Qt::CustomContextMenu);//�����Ҽ��˵�����
	playlistTable->resizeRowsToContents();//�д�С������ƥ��
	//playlistTable->resizeColumnsToContents(); //�д�С������ƥ��
	playlistTable->setEditTriggers(QAbstractItemView::NoEditTriggers);//���ɱ༭
	playlistTable->setStyleSheet("QScrollBar{background:transparent; width: 10px;}"
		"QTableWidget{background-color:rgba(255,238,144,0)}"
		"QScrollBar::handle{background:lightgray; border:2px solid transparent; border-radius:5px;}"
		"QScrollBar::handle:hover{background:orange;}"
		"QScrollBar::sub-line{background:transparent;}"
		"QScrollBar::add-line{background:transparent;}");                   //���ù�������ʽ
}
void FireVideo::paintEvent(QPaintEvent *event)
{
	QPainter pen(this);
	pen.drawPixmap(0, 0, QPixmap(":/FireVideo/Resources/background.jpg"));
	pen.setPen(QColor(216, 212, 44));
	pen.drawLine(QPointF(0, 30), QPointF(450, 30));
	pen.setPen(QColor(250, 244, 12));
	pen.drawLine(QPointF(0, 440), QPointF(450, 440));
	pen.drawLine(QPointF(0, 485), QPointF(450, 485));
}
void FireVideo::FireVideo_Init_InterfaceLevel()
{
	VideoWidget->raise();  //raise����˳��Ӱ�������ؼ��ص�ʱ��ʾ���
	playSlider->raise();
	PlaySchedule->raise();
	PlaySumSchedule->raise();
	HintLabel_Mini->raise();
	HintLabel_Exit->raise();
	HintLabel_OpenFile->raise();
	HintLabel_Pause->raise();
	HintLabel_Play->raise();
	HintLabel_Next->raise();
	HintLabel_Stop->raise();
	HintLabel_Voice->raise();
}
void FireVideo::FireVideo_Init_Connect()
{
	//�����ź�-��
	connect(BtnExit, SIGNAL(clicked()), this, SLOT(close()));
	connect(BtnMinimize, SIGNAL(clicked()), this, SLOT(showMinimized()));
	connect(BtnOpenFile, SIGNAL(clicked()), this, SLOT(BtnOpenFile_Click()));
	connect(BtnPlay, SIGNAL(clicked()), this, SLOT(BtnPlay_Click()));
	connect(BtnPause, SIGNAL(clicked()), this, SLOT(BtnPause_Click()));
	connect(BtnCease, SIGNAL(clicked()), this, SLOT(BtnCease_Click()));
	connect(BtnNext, SIGNAL(clicked()), this, SLOT(BtnNext_Click()));
	//connect(BtnLast, SIGNAL(clicked()), this, SLOT(BtnLast_Click()));
	connect(BtnVoice, SIGNAL(clicked()), this, SLOT(BtnVoice_Click()));
	//�Ҽ��˵�����
	connect(Play, SIGNAL(triggered()), this, SLOT(BtnPlay_Click()));
	connect(Pause, SIGNAL(triggered()), this, SLOT(BtnPause_Click()));
	connect(Stop, SIGNAL(triggered()), this, SLOT(BtnCease_Click()));
	connect(NextVideo, SIGNAL(triggered()), this, SLOT(BtnNext_Click()));
	connect(LastVideo, SIGNAL(triggered()), this, SLOT(BtnLast_Click()));
	connect(HideAll, SIGNAL(triggered()), this, SLOT(BtnHideAll_Click()));
	connect(Restore, SIGNAL(triggered()), this, SLOT(BtnRestore_Click()));
	connect(FullScreen, SIGNAL(triggered()), this, SLOT(BtnFullScreen_Click()));
	connect(Exit_FullScreen, SIGNAL(triggered()), this, SLOT(BtnExitFullScreen_Click()));
	connect(AddVideo, SIGNAL(triggered()), this, SLOT(BtnOpenFile_Click()));
	connect(DeleteCur, SIGNAL(triggered()), this, SLOT(BtnDeleteCur_Click()));
	connect(DeleteAll, SIGNAL(triggered()), this, SLOT(BtnDeleteAll_Click()));
	connect(PlayCur, SIGNAL(triggered()), this, SLOT(BtnPlayCur_Click()));
	connect(NextPlay, SIGNAL(triggered()), this, SLOT(BtnNextPlay_Click()));

	connect(player, SIGNAL(stateChanged(QMediaPlayer::State)), this, SLOT(PlayStateChange(QMediaPlayer::State)));
	connect(player, SIGNAL(durationChanged(qint64)), this, SLOT(Updata_PlaySlider_Duration(qint64)));
	connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(Updata_PlaySlider_Position(qint64)));
	//connect(player, SIGNAL(currentMediaChanged(const QMediaContent &)), this, SLOT(Fire_Media_Changed(const QMediaContent &)));
	//connect(player, SIGNAL(metaDataChanged()), this, SLOT(Media_Changed()));
	connect(volSlider, SIGNAL(valueChanged(int)), this, SLOT(Set_Video_Volume(int)));
	connect(playlistTable, SIGNAL(itemDoubleClicked(QTableWidgetItem*)), this, SLOT(playlistTable_DoubleClicked(QTableWidgetItem*)));
	connect(playlistTable, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(playlistTable_ContextMenu(const QPoint&)));
	//connect(playlistTable, SIGNAL(itemChanged(QTableWidgetItem *)), this, SLOT(playlistTable_Drafting(QTableWidgetItem *currentItem)));
	connect(VideoWidget, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(videoWidget_ContextMenu(const QPoint&)));

}

void FireVideo::BtnOpenFile_Click()
{
	QString DiaTitle = QString::fromLocal8Bit("ѡ����Ƶ�ļ�");
	QString filter = QString::fromLocal8Bit("rmvb �ļ�(*.rmvb);;mp4 �ļ�(*.mp4);;wmv �ļ�(*.wmv);;avi �ļ�(*.avi);;all �ļ�(*.*)");
	QString File = QFileDialog::getOpenFileName(this, DiaTitle, QString(), filter);
	if (File.isEmpty())
		return;
	qint32 CurMediaCount = VideoList->mediaCount();
	VideoList->setCurrentIndex(CurMediaCount); //��֤CurrentIndex���б���λ�ö�Ӧ
	Fire_Add_VideoList(File);
	Fire_Write_VideoList();
}
void FireVideo::Fire_Write_VideoList()   //д���ļ�Ŀ¼URL
{
	QString dir = QApplication::applicationDirPath(); //debugĿ¼
	QFile Vlist(dir + "VideoList.ilst");
	if (Vlist.open(QIODevice::WriteOnly))
	{
		QDataStream OutFile(&Vlist);
		OutFile << VideoListFlies; //����д���ļ����Զ�ɾ��֮ǰ������д�������ݣ�
		Vlist.close();
	}
}
void FireVideo::Fire_Read_VideoList()
{
	QString dir = QApplication::applicationDirPath(); //debugĿ¼
	QFile Vlist(dir + "VideoList.ilst");
	QStringList InFileList;
	if (Vlist.open(QIODevice::ReadOnly))
	{
		QDataStream InFile(&Vlist);
		InFile >> InFileList;   //����д����ʽ��ȡ��һ��д��������ȡ����
		Vlist.close();
	}
	if (InFileList.count() == 0)
		return;
	qint32 cc = InFileList.count();
	foreach(QString Singlefile, InFileList){  //��ʼ�������б�
		Fire_Add_VideoList(Singlefile);
	}
}
void FireVideo::BtnPlay_Click()
{
	if (VideoList->isEmpty())
		return;
	qint32 CurIndex = VideoList->currentIndex();
	if (CurIndex < 0)
		VideoList->setCurrentIndex(0);
	player->play();
	timer->start(8000); //8s��������Ƶ�����еĿؼ�
}
void FireVideo::BtnPause_Click()
{
	if (player->state() == QMediaPlayer::PlayingState)
		player->pause();
}
void FireVideo::BtnCease_Click()
{
	player->stop();
}
void FireVideo::BtnNext_Click()
{
	if (!VideoList->isEmpty()){
		qint32 CurIndex = VideoList->currentIndex();
		qint32 NewIndex = (CurIndex == VideoList->mediaCount() - 1) ? 0 : (CurIndex + 1);
		VideoList->setCurrentIndex(NewIndex);
		if (CurIndex != NewIndex)
			player->setMedia(VideoList->media(NewIndex));
		player->play();
	}
}
void FireVideo::BtnLast_Click()
{
	volSlider->setVisible(false);
	VolValue->setVisible(false);
	if (!VideoList->isEmpty()){
		qint32 CurIndex = VideoList->currentIndex();
		qint32 NewIndex = (CurIndex == 0) ? (VideoList->mediaCount() - 1) : (CurIndex - 1);
		VideoList->setCurrentIndex(NewIndex);
		player->setMedia(VideoList->media(NewIndex));
		player->play();
	}
}
void FireVideo::BtnVoice_Click()
{
	volSlider->setVisible(!(volSlider->isVisible() == true));
	VolValue->setVisible(!(VolValue->isVisible() == true));
}
void FireVideo::Set_Video_Volume(int vol)
{
	player->setVolume(vol);
	QString CurrentVol = QString::number(vol, 10);
	VolValue->setText(CurrentVol + "%");
}
void FireVideo::BtnFullScreen_Click()
{
	VideoWidget->setWindowFlags(Qt::Window);
	VideoWidget->setFullScreen(true);
	timer->stop();  //ȫ��״̬�¹رն�ʱ��
}
void FireVideo::BtnExitFullScreen_Click()
{
	if (VideoWidget->isFullScreen())
	{
		VideoWidget->setWindowFlags(Qt::FramelessWindowHint); //��Ϊ�Ӵ���
		VideoWidget->move(0, 30);
		VideoWidget->resize(450, 400);
		VideoWidget->setVisible(true);
		timer->start(5000); //�򿪶�ʱ��
	}
}
void FireVideo::BtnHideAll_Click()
{
	VideoWidget->setWindowFlags(Qt::Window);
	VideoWidget->resize(450, 400);
	VideoWidget->show();
	this->hide();
}
void FireVideo::BtnRestore_Click()
{
	VideoWidget->setWindowFlags(Qt::FramelessWindowHint); //��Ϊ�Ӵ���
	VideoWidget->setParent(this);
	VideoWidget->move(0, 30);
	VideoWidget->resize(450, 400);
	playSlider->raise();
	PlaySchedule->raise();
	PlaySumSchedule->raise();
	this->show();
	timer->start(5000); //�򿪶�ʱ��
	VideoWidget->setVisible(true);
}
void FireVideo::BtnDeleteCur_Click()
{
	qint32 CurRow = playlistTable->currentRow(); //�����б���ǰ��ѡ�е���
	qint32 CurIndex = VideoList->currentIndex();//��Ƶ�б�ǰ������Ƶϵ��
	if (CurRow == CurIndex)            //�Ƴ�����ƵΪ���ڲ��ŵ���Ƶ��stop
		player->stop();
	VideoList->removeMedia(CurRow); //����Ƶ�б���ɾ��
	playlistTable->removeRow(CurRow); //�ӱ����ɾ��
	VideoListFlies.removeAt(CurRow);
	VideoListName.removeAt(CurRow); //�������б���ɾ��
	VideolistTime.removeAt(CurRow); //��ʱ���б���ɾ��
	Fire_Write_VideoList();
}
void FireVideo::BtnDeleteAll_Click()
{
	if (!VideoList->isEmpty())
	{
		qint32 count = VideoList->mediaCount();
		VideoList->removeMedia(0, count - 1);
		for (int row = 0; playlistTable->rowCount() != 0; row++)//�Ƴ��б�������item
			playlistTable->removeRow(0);
		VideoList->clear();
		VideoListFlies.clear();
		VideoListName.clear();
		VideolistTime.clear();
		player->stop();
		Fire_Write_VideoList();
	}
}
void FireVideo::BtnPlayCur_Click()
{
	qint32 CurRow = playlistTable->currentRow(); //�����б���ǰ��ѡ�е���
	VideoList->setCurrentIndex(CurRow);
	player->setMedia(VideoList->media(CurRow));//��ѡ����Ƶ��Ϊ��ǰ������Ƶ
	player->play();
}
void FireVideo::BtnNextPlay_Click()
{
	qint32 CurRow = playlistTable->currentRow();
	qint32 CurIndex = VideoList->currentIndex();
	if (CurIndex == CurRow) //��һ��������ƵΪ���ڲ��ŵ���Ƶ
		return;
	qint32 NextIndex = (CurIndex == (playlistTable->rowCount() - 1) ? 0 : CurIndex + 1);
	QMediaContent media2 = VideoList->media(CurRow);
	QString CurRowName = VideoListName.at(CurRow);
	QString CurRowFile = VideoListFlies.at(CurRow);
	if (CurIndex < CurRow)   //��һ��������Ƶ�ڵ�ǰ������Ƶ�б��·�����ɾ���
	{
		VideoList->removeMedia(CurRow); //ɾ��֮ǰλ�ô��Ĳ�����Ƶ
		VideoList->insertMedia(NextIndex, media2); //�ڵ�ǰ������Ƶ����������������Ƶ��insertMedia��CurIndex��Media2������CurIndex֮ǰ����ý��
		VideoListName.removeAt(CurRow);
		VideoListName.insert(NextIndex, CurRowName);
		VideoListFlies.removeAt(CurRow);
		VideoListFlies.insert(NextIndex, CurRowFile);
		VideoList->setCurrentIndex(CurIndex); //��֤��ǰϵ������
	}
	else if (CurIndex > CurRow)   //��һ��������Ƶ�ڵ�ǰ������Ƶ�б��Ϸ����Ȳ��ɾ
	{
		VideoList->insertMedia(NextIndex, media2);
		VideoList->removeMedia(CurRow);
		VideoListName.insert(NextIndex, CurRowName);
		VideoListName.removeAt(CurRow);
		VideoListFlies.insert(NextIndex, CurRowFile);
		VideoListFlies.removeAt(CurRow);
		VideoList->setCurrentIndex(CurIndex - 1); //��֤��ǰϵ�����б����Ӧ
	}
	Fire_Write_VideoList();   //�����±��ŵ���Ƶ����д���ļ���
	for (int i = 0; i < VideoListName.count(); i++) //���±��ű���ļ�˳��
		playlistTable->item(i, 0)->setText(VideoListName.at(i));
}

void FireVideo::PlayStateChange(QMediaPlayer::State state)
{
	BtnPlay->setEnabled(state == QMediaPlayer::PausedState);
	BtnPlay->setVisible(state == QMediaPlayer::PausedState);
	BtnPause->setEnabled(!(state == QMediaPlayer::PausedState));
	BtnPause->setVisible(!(state == QMediaPlayer::PausedState));
	if (state == QMediaPlayer::PlayingState)  //����״̬
	{
		VideoWidget->setEnabled(true); //ʹ������Ļ�ϵ�������¼�
		VideoWidget->setVisible(true);
		VideoInfoLable->setVisible(true);
		playSlider->setVisible(true);
		PlaySchedule->setVisible(true);
		PlaySumSchedule->setVisible(true);
		BtnPause->setVisible(true);
		BtnPlay->setVisible(false);
		qint32 CurIndex = VideoList->currentIndex();
		VideoInfoLable->setText(VideoListName.at(CurIndex));//��ʾ���ڲ��ŵ���Ƶ����
		Fire_ListTable_color();
	}
	if (state == QMediaPlayer::PausedState) //��ͣ״̬
	{
		VideoWidget->setEnabled(true);
		//VideoWidget->setVisible(true);
		VideoInfoLable->setVisible(true);
		playSlider->setVisible(true);
		PlaySchedule->setVisible(true);
		PlaySumSchedule->setVisible(true);
		BtnPause->setVisible(false);
		BtnPlay->setVisible(true);
	}
	if (state == QMediaPlayer::StoppedState) //ֹͣ״̬
	{
		VideoWidget->setVisible(false);
		VideoWidget->setEnabled(false);
		VideoInfoLable->clear();
		volSlider->setVisible(false);
		VolValue->setVisible(false);
		playSlider->setVisible(false);
		PlaySchedule->setVisible(false);
		PlaySumSchedule->setVisible(false);
		BtnPlay->setVisible(true);
		BtnPlay->setEnabled(true);
		BtnPause->setVisible(false);
		Fire_ListTable_color();
	}

}
void FireVideo::Fire_Media_Changed(const QMediaContent & MC)
{
	/*if (MC.isNull() == false)
	{*/
	qint32 CurRow = VideoList->currentIndex();
	qint32 a = VideoList->mediaCount();
	qint32 k = VideoListName.count();
	QString filename = VideoListName.at(CurRow);
	VideoInfoLable->setText(filename);//���µ�ǰ������Ƶ�ļ���Ϣ
	/*}*/
}
void FireVideo::Updata_PlaySlider_Duration(qint64 duration)
{
	playSlider->setRange(0, duration);
	playSlider->setEnabled(true);
	QString totaltime = CalVideoPlayTime();//�����ļ���ʱ��������������
	PlaySumSchedule->setText(totaltime);
}
void FireVideo::Updata_PlaySlider_Position(qint64 pos)
{
	if (pos>0 && pos == player->duration())//�Զ�������һ��
		BtnNext_Click();
	playSlider->setValue(pos);
	PlayingPosition = pos;
	QString CurTimeS = CalVideoCurPlayTime();
	PlaySchedule->setText(CurTimeS);//���µ�ǰ����ʱ��	
}

void FireVideo::MTimeSlot()
{
	if (player->state() == QMediaPlayer::PausedState) //��ͣ״̬�²�������Ļ�ؼ�
		return;
	playSlider->setVisible(false);
	PlaySchedule->setVisible(false);
	PlaySumSchedule->setVisible(false);
	timer->stop();
}

qint32 FireVideo::Get_Video_Position()
{
	return PlayingPosition;
}

void FireVideo::playlistTable_DoubleClicked(QTableWidgetItem* item)
{
	qint32 RowNum = item->row();
	VideoList->setCurrentIndex(RowNum); //�ı䵱ǰ����ϵ�������б����Ӧ����ʼϵ��Ϊ-1��;
	player->setMedia(VideoList->media(RowNum));//��ѡ����Ƶ��Ϊ��ǰ������Ƶ
	player->play();
	timer->start(8000); //ÿ8s�����һ��ʱ���жϣ����ذ���
}
void FireVideo::keyPressEvent(QKeyEvent *event)
{
	qint16 PerSpeedLength = playSlider->maximum() / 50; //ÿ�ο���ĳ���
	qint16 PerDownLength = playSlider->maximum() / 50; //ÿ�κ��˳���
	qint16 CurVol = volSlider->value();
	switch (event->key())  //switch�ڲ������������
	{
	case  Qt::Key_Right:
		PlayingPosition = PlayingPosition + PerSpeedLength;
		player->setPosition(PlayingPosition);
		player->play();
		break;
	case  Qt::Key_Left:
		PlayingPosition = PlayingPosition - PerDownLength;
		player->setPosition(PlayingPosition);
		player->play();
		break;
	case  Qt::Key_Up:
		volSlider->setValue(CurVol + 2);
		break;
	case  Qt::Key_Down:
		volSlider->setValue(CurVol - 2);
		break;
	case  Qt::Key_Shift:
		showMinimized();
		break;
	case  Qt::Key_Space:
		player->pause();
		break;
	default:
		break;
	}
	QWidget::keyPressEvent(event);
}

void FireVideo::wheelEvent(QWheelEvent*event)
{
	qint16 VolValue = volSlider->value();
	if (event->delta() > 0) //�������ϻ�
	{
		volSlider->setValue(VolValue + 1);
	}
	else   //�»�
	{
		volSlider->setValue(VolValue - 1);
	}
	QWidget::wheelEvent(event);
}
void FireVideo::playlistTable_ContextMenu(const QPoint& pos)
{
	if (playlistTable->itemAt(pos)) //����һ�λ�ò���item��
		Item_VideoListMenu->exec(QCursor::pos());
	else
		VideoListMenu->exec(QCursor::pos());
}
void FireVideo::playlistTable_Drafting(QTableWidgetItem *currentItem)
{
	qint32 C = VideoList->currentIndex();
}
void FireVideo::videoWidget_ContextMenu(const QPoint& pos)
{
	if (!VideoWidget->isFullScreen()) //��ȫ��״̬�µ��һ���Ӧ�˵�
		VideoWidgetMenu->exec(QCursor::pos());
	else
		FullScreen_VideoWidgetMenu->exec(QCursor::pos());
}
void FireVideo::contextMenuEvent(QContextMenuEvent *event)
{
	//if (event->pos() == playlistTable->pos())
	//VideoListMenu->exec(QCursor::pos());
}
void FireVideo::dragEnterEvent(QDragEnterEvent *event)
{
	if (event->mimeData()->hasFormat("text/uri-list"))
		event->acceptProposedAction();
}
void FireVideo::dropEvent(QDropEvent *event)
{
	QList<QUrl> urls = event->mimeData()->urls(); //urls�洢�����ļ�����ϸ·�����磺D:/FireVideo/Resources/Play.rmvb
	if (urls.isEmpty())
		return;
	QStringList dropfilename;
	foreach(QUrl u, urls){
		if (u.toString().right(5) == QString(".rmvb") || \
			u.toString().right(4) == QString(".mp4") || \
			u.toString().right(4) == QString(".wmv") || \
			u.toString().right(4) == QString(".avi") || \
			u.toString().right(4) == QString(".mkv"))
		{
			QString f = u.toString();
			dropfilename.append(u.toLocalFile());
		}
	}
	if (!dropfilename.isEmpty()){
		for (auto it = dropfilename.begin(); it != dropfilename.end(); it++) //������ק�����ļ��е�ÿ���ļ����������
			Fire_Add_VideoList(*it);
		Fire_Write_VideoList();  //������ӵ���Ƶ�ļ�д���ļ���
	}
}

void FireVideo::Fire_Add_VideoList(QString& file)
{
	QFileInfo FileInfo(file);
	for (int i = 0; i < VideoListName.count(); i++)   //��ͬ�ļ������
		if (FileInfo.fileName() == VideoListName[i])  //�����ʼ���׶�VideoListNameΪ��
			return;
	QTableWidgetItem *item = new QTableWidgetItem;
	item->setFont(QFont(QString::fromLocal8Bit("����"), 10));//����Ƶ�б����д�������
	VideoList->addMedia(QUrl::fromLocalFile(file));
	VideoListFlies.append(file);
	VideoListName.append(FileInfo.fileName());
	playlistTable->insertRow(playlistTable->rowCount());
	playlistTable->setItem(playlistTable->rowCount() - 1, 0, item);
	playlistTable->item(playlistTable->rowCount() - 1, 0)->setText(FileInfo.fileName());
}

QString FireVideo::CalVideoPlayTime()
{
	qint64 TotalTime = player->duration();//�ܹ�ʱ��ms
	TotalTime /= 1000;
	qint64 TotalM = TotalTime / 60; //�õ�ʱ����
	qint32 TotalS = TotalTime % 60;//�õ�ʱ����
	QString StotalM = QString::number(TotalM);
	QString StotalS = QString::number(TotalS);
	if (TotalM < 10)
		StotalM = "0" + StotalM;
	if (TotalS < 10)
		StotalS = "0" + StotalS;
	QString TotalTimeS = StotalM + ":" + StotalS;
	VideolistTime.append(TotalTimeS); //�������ʱ�����������
	return TotalTimeS;
}
QString FireVideo::CalVideoCurPlayTime()
{
	qint16 CurTime = PlayingPosition / 1000;
	qint16 CurM = CurTime / 60;
	qint16 CurS = CurTime % 60;
	QString ScurM = QString::number(CurM);
	QString ScurS = QString::number(CurS);
	if (CurM < 10)
		ScurM = "0" + ScurM;
	if (CurS < 10)
		ScurS = "0" + ScurS;
	return  (ScurM + ":" + ScurS);
}
void FireVideo::Fire_ListTable_color()
{
	if (VideoList->isEmpty())
		return;
	for (int row = 0; row < playlistTable->rowCount(); row++)
		playlistTable->item(row, 0)->setBackgroundColor(QColor(255, 238, 144));
	if (player->state() == QMediaPlayer::StoppedState) //ֹͣ״̬����
		return;
	qint32 CurIndex = VideoList->currentIndex();
	if (CurIndex >= 0)
		playlistTable->item(CurIndex, 0)->setBackgroundColor(QColor(255, 255, 255)); //�����ڲ��ŵ���Ƶ������Ϊ��ɫ
}