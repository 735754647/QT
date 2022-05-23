#include "QtandLeisai.h"
#include "LTDMC.h"
#include <QDebug>
#include<qmessagebox.h>

double encPos = 0; //反馈位置
ushort _CardID = 0;//卡号
short res;//执行返回值
ushort sDir; //运动方向，0：负方向，1：正方向
ushort AbsAndRel; //绝对定位和相对定位
bool MoveSta=false;//轴状态

QtandLeisai::QtandLeisai(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	InitTableW();

	this->_time = new QTimer(this);//初始化定时器事件
	//QString nowPS;
		connect(_time, &QTimer::timeout, [=]() {
		dmc_get_encoder_unit(_CardID, 0, &encPos);//读取指定轴反馈位置值
		 ui.LB_MovePS->setText(QString::number(encPos, '.', 0));
		 if (dmc_check_done(_CardID, 0) == 0) // 读取指定轴运动状态
		 {
			 MoveSta = true;
			 ui.LB_Aixs_Move_Sta->setText("运行中");
			 ui.LB_Aixs_Move_Sta->setStyleSheet("QLabel{background-color:rgb(200,101,102);}");  //设置样式表
		 }
		 else
		 {
			 MoveSta = false;
			 ui.LB_Aixs_Move_Sta->setText("停止");
			 ui.LB_Aixs_Move_Sta->setStyleSheet("QLabel{background-color:rgb(0,0,0);}");  //设置样式表
		 }
		 ushort errcode = 0;
		 nmc_get_errcode(_CardID, 2, &errcode);
		 if (!errcode == 0)
		 {
			 QMessageBox::warning(this, "Title", "", "EtherCAT总线出错");
		 }
		 ushort Axis_State_machine = 0;
		 nmc_get_axis_state_machine(0, 0, &Axis_State_machine);
		 switch (Axis_State_machine)// 读取指定轴状态机
		 {
		 case 0:
			 ui.LB_AixsSta->setText("轴处于未启动状态");
			 break;
		 case 1:

			 ui.LB_AixsSta->setText("轴处于启动禁止状态");
			 break;
		 case 2:
			 ui.LB_AixsSta->setText("轴处于准备启动状态");
			 break;
		 case 3:
			 ui.LB_AixsSta->setText("轴处于启动状态");
			 break;
		 case 4:
			 ui.LB_AixsSta->setText("轴处于准备启动状态");
			 break;
		 case 5:
			 ui.LB_AixsSta->setText("轴处于停止状态");
			 break;
		 case 6:
			 ui.LB_AixsSta->setText("轴处于错误触发状态");
			 break;
		 case 7:
			 ui.LB_AixsSta->setText("轴处于错误状态");
			 break;
		 };
		 ushort n = 0;
		 for (ushort i = 0; i < 80; i++)
		 {
			nmc_read_inbit_extern(_CardID, 2, 1002, i, &n);
			 if (n == 0)
			 {
				 ui.TK->item(i, 1)->setBackground(Qt::red);
			 }
			 else
			 {
				 ui.TK->item(i, 1)->setBackground(Qt::white);
			 }
		 }
		 for (ushort i = 0; i < 80; i++)
		 {
			 nmc_read_inbit_extern(_CardID, 2, 1002, i+80, &n);
			 if (n == 0)
			 {
				 ui.TK->item(i, 3)->setBackground(Qt::red);
			 }
			 else
			 {
				 ui.TK->item(i, 3)->setBackground(Qt::white);
			 }
		 }
		 for (ushort i = 0; i < 80; i++)
		 {
			 nmc_read_outbit_extern(_CardID, 2, 1002, i, &n);
			 if (n == 0)
			 {
				 ui.TK->item(i, 5)->setBackground(Qt::red);
			 }
			 else
			 {
				 ui.TK->item(i, 5)->setBackground(Qt::white);
			 }
		 }
		 for (ushort i = 0; i < 80; i++)
		 {
			 nmc_read_outbit_extern(_CardID, 2, 1002, i+80, &n);
			 if (n == 0)
			 {
				 ui.TK->item(i, 7)->setBackground(Qt::red);
			 }
			 else
			 {
				 ui.TK->item(i, 7)->setBackground(Qt::white);
			 }
		 }
		});
}
void QtandLeisai::on_Bt_CardLint_clicked()
{
	short num = dmc_board_init();//获取卡数量
	if (num <= 0 || num > 8)
	{
		QMessageBox::warning(this, "Title", "初始卡失败!", "出错");
	}
	else
	{
		QMessageBox::warning(this, "Title", "初始卡成功!", "初始卡成功");
	}
	ushort _num = 0;
	unsigned long cardids;
	ushort cardtypes;
	 res = dmc_get_CardInfList( &_num, &cardids, &cardtypes);
	if (res != 0)
	{
		QMessageBox::warning(this, "Title", "获取卡信息失败");
	}
	else
	{
		QMessageBox::warning(this, "Title", "获取卡信息成功");
			
	}
	_CardID = cardtypes;
	
}
void QtandLeisai::on_Bt_AxisEn_clicked()
{
	res = nmc_set_axis_enable(_CardID, 0);// 使能对应轴
	if (res != 0)
	{
		QMessageBox::warning(this, "Title", "nmc_set_axis_enable == " + res);
	}
}
void QtandLeisai::on_Bt_AxisRestEn_clicked()
{
	res = nmc_set_axis_disable(_CardID, 0);
	if (res != 0)
	{
		QMessageBox::warning(this, "Title", "nmc_set_axis_enable == " + res);
	}
}
void QtandLeisai::on_Bt_AxisJOGAdd_clicked()
{
           QString	JogVlue = ui.LE_JogMoveVlue->text(); 
            double	dMaxVel = JogVlue.toDouble();
			res = dmc_pmove_unit(_CardID, 0, dMaxVel, 0); //0:相对定位  1：绝对定位
			if (res != 0)
			{
				QMessageBox::warning(this, "Title", "dmc_vmove == " + res);
			}
}
void QtandLeisai::on_Bt_AxisJOGSub_clicked()
{
	QString	JogVlue = ui.LE_JogMoveVlue->text(); //val=123.45
	double	dMaxVel = JogVlue.toDouble();
	res = dmc_pmove_unit(_CardID, 0, -dMaxVel, 0);
	if (res != 0)
	{
		QMessageBox::warning(this, "Title", "nmc_set_axis_enable == " + res);
	}
}
void QtandLeisai::on_Bt_AxisRunAbs_clicked()
{
	Move_AbsOrRel(1);
}
void QtandLeisai::on_Bt_AxisRunRel_clicked()
{
	Move_AbsOrRel(0);
}
void QtandLeisai::on_Bt_AxisStop_clicked()
{
	ushort axis = 0; //轴号
	ushort stop_mode = 0; //制动方式，0：减速停止，1：紧急停止
	dmc_stop(_CardID, axis, stop_mode);
}
void QtandLeisai::on_Bt_AxisGoHome_clicked()
{
	ushort state = 0;
	ushort axis = 0;
	short res = nmc_home_move(_CardID, axis);//启动回零     
	if (res != 0)
	{
		QMessageBox::warning(this, "Title", "nmc_home_move == " + res);
		return;
	}
	while (dmc_check_done(_CardID, axis) == 0)//等待运动停止
	{
		
	}
	res = dmc_get_home_result(_CardID, axis,  &state);//判断回零结果
	if (res == 0)
	{
		if (state == 1)
		{
			QMessageBox::warning(this, "Title", "回零成功!");
		}
		else
		{
			QMessageBox::warning(this, "Title", "回零失败!");
		}
	}
	else
	{
		QMessageBox::warning(this, "Title", "dmc_get_home_result == " + res);
	}
}
void QtandLeisai::on_Bt_CleanAisxWarn_clicked()
{
	short res = nmc_clear_axis_errcode(0, 0);//清除轴错误
	if (res != 0)
	{
		QMessageBox::warning(this, "Title", "Clean Success！" );
	}
}
void QtandLeisai::on_Bt_CardClose_clicked()
{
	_time->stop();
	 res = dmc_board_close();
	 if (res != 0)
	 {
		 QMessageBox::warning(this, "Title", "Close Erro!" );
		 return;
	 }
	
}
void QtandLeisai::on_Bt_RunTime_clicked()
{
	//判断定时器有没有工作
	if (_time->isActive() == false)
	{
		_time->start(100);//启动定时器
	}
}
void QtandLeisai::on_Bt_SetOut_clicked()
{
	QString Out= ui.LE_OutPutVule->text(); //从窗体获得运行距离
	double OutNum = Out.toDouble();
	short s;
	s=nmc_write_outbit_extern(_CardID, 2, 1002, OutNum, 0);
	if (s != 0)
	{
		QMessageBox::warning(this, "Title", "SET OUT Erro ");
	}
}
void QtandLeisai::on_Bt_RestOut_clicked()
{
	QString Out = ui.LE_OutPutVule->text(); //从窗体获得运行距离
	double OutNum = Out.toDouble();
	short s;
	s = nmc_write_outbit_extern(_CardID, 2, 1002, OutNum, 1);
	if (s != 0)
	{
		QMessageBox::warning(this, "Title", "REST OUT Erro ");
	}
}
void QtandLeisai::on_chB_MoveOri_stateChanged(int arg1)
{
	if (arg1==2)
	{
		sDir = 1; //正向
	}
	else if (arg1 == 1)
	{
		sDir = 0;//负向
	}	
}
void QtandLeisai::Move_AbsOrRel(ushort AbsAndRel)
{
	if (!MoveSta)
	{
		ushort axis = 0; //轴号
		double dEquiv; //脉冲当量
		double dStartVel;//起始速度
		double dMaxVel;//运行速度
		double M_ps;//运行速度
		double dTacc;//加速时间
		double dTdec;//减速时间
		double dStopVel;//停止速度
		double dS_para;//S段时间
		QString val;
		QString va2;
		ushort State_Machine = 0;//获取轴状态机
		dEquiv = 1.0;
		dStartVel = 0.00;
		val = ui.LE_AxisSpeed->text(); //val=123.45
		dMaxVel = val.toDouble();
		dTacc = 0.01;
		dTdec = 0.01;
		dStopVel = 0;
		dS_para = 0;
		short res = 0;
		res = dmc_set_profile_unit(_CardID, axis, dStartVel, dMaxVel, dTacc, dTdec, dStopVel);//设置速度参数
		res = dmc_set_s_profile(_CardID, axis, 0, dS_para);//设置S段速度参数
		res = dmc_set_dec_stop_time(_CardID, axis, dTdec); //设置减速停止时间
		va2 = ui.LE_AxisPosition->text(); //从窗体获得运行距离
		M_ps = va2.toDouble();
		res = dmc_pmove_unit(_CardID, 0, M_ps, AbsAndRel); //0号卡 0号轴 移动距离M_ps 1：绝对定位
		if (res != 0)
		{
			QMessageBox::warning(this, "Title", "dmc_pmove_unit == " + res);
		}
	}
}
void QtandLeisai::InitTableW()
{
	ui.TK->setRowCount(80);//设置行数
	ui.TK->setColumnCount(8);//设置列数
	ui.TK->setWindowTitle("I/O状态");//设置表标题
	QStringList HE;//存储表头变量
	HE << "名称" << "input" << "名称" << "input" << "名称" << "output" << "名称" << "output";//设置头标题
	ui.TK->setHorizontalHeaderLabels(HE);//把头标题添加到表
	ui.TK->setColumnWidth(0, 50);//设置每一列的宽度
	ui.TK->setColumnWidth(1, 150);
	ui.TK->setColumnWidth(2, 50);
	ui.TK->setColumnWidth(3, 150);
	ui.TK->setColumnWidth(4, 50);//设置每一列的宽度
	ui.TK->setColumnWidth(5, 150);
	ui.TK->setColumnWidth(6, 50);
	ui.TK->setColumnWidth(7, 150);
	ui.TK->setShowGrid(true); //设置显示格子线
	ui.TK->setEditTriggers(QAbstractItemView::NoEditTriggers); //禁止编辑
	ui.TK->horizontalHeader()->setStretchLastSection(true); //行头自适应表格
	ui.TK->horizontalHeader()->setFont(QFont("song", 2));//设置表头字体加粗
	QFont font = ui.TK->horizontalHeader()->font();
	font.setBold(true);
	ui.TK->horizontalHeader()->setFont(font);
	ui.TK->horizontalHeader()->setStyleSheet("QHeaderView::section{background:lightblue;}"); //skyblue设置表头背景色
	ui.TK->setStyleSheet("selection-background-color:lightblue;"); //设置选中背景色
	ui.TK->setFont(QFont("新宋体", 1));//所有单元格的字体  设置成一样
#pragma region MyRegion
//QTextCodec *pcode = QTextCodec::codecForName("GBK");//设置显示格式  pcode->toUnicode("I/O状态")
//ui.TK->setRowHeight(1, 60);//设置行高
//ui.TK->setStyleSheet("QTableWidget::item{border:1px solid ;}");//设置线粗格式
//ui.TK->setSelectionBehavior(QAbstractItemView::SelectRows); //整行选中的方式
//点击表时不对表头行光亮（获取焦点）
//ui.TK->horizontalHeader()->setHighlightSections(false);
//ui.TK->setStyleSheet(qssTV);
//ui.TK->horizontalHeader()->setHighlightSections(false);         //点击表头时不对表头光亮
//ui.TK->setSelectionMode(QAbstractItemView::ContiguousSelection);//选中模式为多行选中
//ui.TK->setSelectionBehavior(QAbstractItemView::SelectRows);
//ui.TK->item(4, 3)->setForeground(Qt::red);//设置第四行低三列字体颜色为红
//ui.TK->setRowHeight(4, 50);//设置第四行高度为50
#pragma endregion

	for (int i = 0; i < 80; i++)
	{
		ui.TK->setItem(i, 0, new QTableWidgetItem("I" + QString::number(i)));//设置0列的数据
		ui.TK->setItem(i, 1, new QTableWidgetItem(""));
		ui.TK->setItem(i, 2, new QTableWidgetItem("I" + QString::number(i + 80)));//设置0列的数据
		ui.TK->setItem(i, 3, new QTableWidgetItem(""));
	}
	for (int j = 0; j < 80; j++)
	{
		ui.TK->setItem(j, 4, new QTableWidgetItem("O" + QString::number(j)));
		ui.TK->setItem(j, 5, new QTableWidgetItem(""));
		ui.TK->setItem(j, 6, new QTableWidgetItem("O" + QString::number(j + 80)));
		ui.TK->setItem(j, 7, new QTableWidgetItem(""));
	}
	//bool InputStat[20] = { 0,1,1,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,0 };//采用循环读取I/O
	//bool OutputStat[20] = { 0,1,1,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1 };

	//ushort nodeID = decimal.ToUInt16(nud_nodeID.Value);
	//for (int i = 0; i < 20; i++)//循环显示到表格控件
	//{
	//	if (InputStat[i] == true)
	//	{
	//		ui.TK->item(i, 1)->setBackground(Qt::red);//设置第四行低三列背景颜色为红
	//	}
	//	else
	//	{
	//		ui.TK->item(i, 1)->setBackground(Qt::white);
	//	}
	//	if (OutputStat[i] == true)
	//	{
	//		ui.TK->item(i, 3)->setBackground(Qt::red);//设置第四行低三列背景颜色为红
	//	}
	//	else
	//	{
	//		ui.TK->item(i, 3)->setBackground(Qt::white);
	//	}
	//}
	ui.TK->show();
 }




