#include "QtandLeisai.h"
#include "LTDMC.h"
#include <QDebug>
#include<qmessagebox.h>

double encPos = 0; //����λ��
ushort _CardID = 0;//����
short res;//ִ�з���ֵ
ushort sDir; //�˶�����0��������1��������
ushort AbsAndRel; //���Զ�λ����Զ�λ
bool MoveSta=false;//��״̬

QtandLeisai::QtandLeisai(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	InitTableW();

	this->_time = new QTimer(this);//��ʼ����ʱ���¼�
	//QString nowPS;
		connect(_time, &QTimer::timeout, [=]() {
		dmc_get_encoder_unit(_CardID, 0, &encPos);//��ȡָ���ᷴ��λ��ֵ
		 ui.LB_MovePS->setText(QString::number(encPos, '.', 0));
		 if (dmc_check_done(_CardID, 0) == 0) // ��ȡָ�����˶�״̬
		 {
			 MoveSta = true;
			 ui.LB_Aixs_Move_Sta->setText("������");
			 ui.LB_Aixs_Move_Sta->setStyleSheet("QLabel{background-color:rgb(200,101,102);}");  //������ʽ��
		 }
		 else
		 {
			 MoveSta = false;
			 ui.LB_Aixs_Move_Sta->setText("ֹͣ");
			 ui.LB_Aixs_Move_Sta->setStyleSheet("QLabel{background-color:rgb(0,0,0);}");  //������ʽ��
		 }
		 ushort errcode = 0;
		 nmc_get_errcode(_CardID, 2, &errcode);
		 if (!errcode == 0)
		 {
			 QMessageBox::warning(this, "Title", "", "EtherCAT���߳���");
		 }
		 ushort Axis_State_machine = 0;
		 nmc_get_axis_state_machine(0, 0, &Axis_State_machine);
		 switch (Axis_State_machine)// ��ȡָ����״̬��
		 {
		 case 0:
			 ui.LB_AixsSta->setText("�ᴦ��δ����״̬");
			 break;
		 case 1:

			 ui.LB_AixsSta->setText("�ᴦ��������ֹ״̬");
			 break;
		 case 2:
			 ui.LB_AixsSta->setText("�ᴦ��׼������״̬");
			 break;
		 case 3:
			 ui.LB_AixsSta->setText("�ᴦ������״̬");
			 break;
		 case 4:
			 ui.LB_AixsSta->setText("�ᴦ��׼������״̬");
			 break;
		 case 5:
			 ui.LB_AixsSta->setText("�ᴦ��ֹͣ״̬");
			 break;
		 case 6:
			 ui.LB_AixsSta->setText("�ᴦ�ڴ��󴥷�״̬");
			 break;
		 case 7:
			 ui.LB_AixsSta->setText("�ᴦ�ڴ���״̬");
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
	short num = dmc_board_init();//��ȡ������
	if (num <= 0 || num > 8)
	{
		QMessageBox::warning(this, "Title", "��ʼ��ʧ��!", "����");
	}
	else
	{
		QMessageBox::warning(this, "Title", "��ʼ���ɹ�!", "��ʼ���ɹ�");
	}
	ushort _num = 0;
	unsigned long cardids;
	ushort cardtypes;
	 res = dmc_get_CardInfList( &_num, &cardids, &cardtypes);
	if (res != 0)
	{
		QMessageBox::warning(this, "Title", "��ȡ����Ϣʧ��");
	}
	else
	{
		QMessageBox::warning(this, "Title", "��ȡ����Ϣ�ɹ�");
			
	}
	_CardID = cardtypes;
	
}
void QtandLeisai::on_Bt_AxisEn_clicked()
{
	res = nmc_set_axis_enable(_CardID, 0);// ʹ�ܶ�Ӧ��
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
			res = dmc_pmove_unit(_CardID, 0, dMaxVel, 0); //0:��Զ�λ  1�����Զ�λ
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
	ushort axis = 0; //���
	ushort stop_mode = 0; //�ƶ���ʽ��0������ֹͣ��1������ֹͣ
	dmc_stop(_CardID, axis, stop_mode);
}
void QtandLeisai::on_Bt_AxisGoHome_clicked()
{
	ushort state = 0;
	ushort axis = 0;
	short res = nmc_home_move(_CardID, axis);//��������     
	if (res != 0)
	{
		QMessageBox::warning(this, "Title", "nmc_home_move == " + res);
		return;
	}
	while (dmc_check_done(_CardID, axis) == 0)//�ȴ��˶�ֹͣ
	{
		
	}
	res = dmc_get_home_result(_CardID, axis,  &state);//�жϻ�����
	if (res == 0)
	{
		if (state == 1)
		{
			QMessageBox::warning(this, "Title", "����ɹ�!");
		}
		else
		{
			QMessageBox::warning(this, "Title", "����ʧ��!");
		}
	}
	else
	{
		QMessageBox::warning(this, "Title", "dmc_get_home_result == " + res);
	}
}
void QtandLeisai::on_Bt_CleanAisxWarn_clicked()
{
	short res = nmc_clear_axis_errcode(0, 0);//��������
	if (res != 0)
	{
		QMessageBox::warning(this, "Title", "Clean Success��" );
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
	//�ж϶�ʱ����û�й���
	if (_time->isActive() == false)
	{
		_time->start(100);//������ʱ��
	}
}
void QtandLeisai::on_Bt_SetOut_clicked()
{
	QString Out= ui.LE_OutPutVule->text(); //�Ӵ��������о���
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
	QString Out = ui.LE_OutPutVule->text(); //�Ӵ��������о���
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
		sDir = 1; //����
	}
	else if (arg1 == 1)
	{
		sDir = 0;//����
	}	
}
void QtandLeisai::Move_AbsOrRel(ushort AbsAndRel)
{
	if (!MoveSta)
	{
		ushort axis = 0; //���
		double dEquiv; //���嵱��
		double dStartVel;//��ʼ�ٶ�
		double dMaxVel;//�����ٶ�
		double M_ps;//�����ٶ�
		double dTacc;//����ʱ��
		double dTdec;//����ʱ��
		double dStopVel;//ֹͣ�ٶ�
		double dS_para;//S��ʱ��
		QString val;
		QString va2;
		ushort State_Machine = 0;//��ȡ��״̬��
		dEquiv = 1.0;
		dStartVel = 0.00;
		val = ui.LE_AxisSpeed->text(); //val=123.45
		dMaxVel = val.toDouble();
		dTacc = 0.01;
		dTdec = 0.01;
		dStopVel = 0;
		dS_para = 0;
		short res = 0;
		res = dmc_set_profile_unit(_CardID, axis, dStartVel, dMaxVel, dTacc, dTdec, dStopVel);//�����ٶȲ���
		res = dmc_set_s_profile(_CardID, axis, 0, dS_para);//����S���ٶȲ���
		res = dmc_set_dec_stop_time(_CardID, axis, dTdec); //���ü���ֹͣʱ��
		va2 = ui.LE_AxisPosition->text(); //�Ӵ��������о���
		M_ps = va2.toDouble();
		res = dmc_pmove_unit(_CardID, 0, M_ps, AbsAndRel); //0�ſ� 0���� �ƶ�����M_ps 1�����Զ�λ
		if (res != 0)
		{
			QMessageBox::warning(this, "Title", "dmc_pmove_unit == " + res);
		}
	}
}
void QtandLeisai::InitTableW()
{
	ui.TK->setRowCount(80);//��������
	ui.TK->setColumnCount(8);//��������
	ui.TK->setWindowTitle("I/O״̬");//���ñ����
	QStringList HE;//�洢��ͷ����
	HE << "����" << "input" << "����" << "input" << "����" << "output" << "����" << "output";//����ͷ����
	ui.TK->setHorizontalHeaderLabels(HE);//��ͷ������ӵ���
	ui.TK->setColumnWidth(0, 50);//����ÿһ�еĿ��
	ui.TK->setColumnWidth(1, 150);
	ui.TK->setColumnWidth(2, 50);
	ui.TK->setColumnWidth(3, 150);
	ui.TK->setColumnWidth(4, 50);//����ÿһ�еĿ��
	ui.TK->setColumnWidth(5, 150);
	ui.TK->setColumnWidth(6, 50);
	ui.TK->setColumnWidth(7, 150);
	ui.TK->setShowGrid(true); //������ʾ������
	ui.TK->setEditTriggers(QAbstractItemView::NoEditTriggers); //��ֹ�༭
	ui.TK->horizontalHeader()->setStretchLastSection(true); //��ͷ����Ӧ���
	ui.TK->horizontalHeader()->setFont(QFont("song", 2));//���ñ�ͷ����Ӵ�
	QFont font = ui.TK->horizontalHeader()->font();
	font.setBold(true);
	ui.TK->horizontalHeader()->setFont(font);
	ui.TK->horizontalHeader()->setStyleSheet("QHeaderView::section{background:lightblue;}"); //skyblue���ñ�ͷ����ɫ
	ui.TK->setStyleSheet("selection-background-color:lightblue;"); //����ѡ�б���ɫ
	ui.TK->setFont(QFont("������", 1));//���е�Ԫ�������  ���ó�һ��
#pragma region MyRegion
//QTextCodec *pcode = QTextCodec::codecForName("GBK");//������ʾ��ʽ  pcode->toUnicode("I/O״̬")
//ui.TK->setRowHeight(1, 60);//�����и�
//ui.TK->setStyleSheet("QTableWidget::item{border:1px solid ;}");//�����ߴָ�ʽ
//ui.TK->setSelectionBehavior(QAbstractItemView::SelectRows); //����ѡ�еķ�ʽ
//�����ʱ���Ա�ͷ�й�������ȡ���㣩
//ui.TK->horizontalHeader()->setHighlightSections(false);
//ui.TK->setStyleSheet(qssTV);
//ui.TK->horizontalHeader()->setHighlightSections(false);         //�����ͷʱ���Ա�ͷ����
//ui.TK->setSelectionMode(QAbstractItemView::ContiguousSelection);//ѡ��ģʽΪ����ѡ��
//ui.TK->setSelectionBehavior(QAbstractItemView::SelectRows);
//ui.TK->item(4, 3)->setForeground(Qt::red);//���õ����е�����������ɫΪ��
//ui.TK->setRowHeight(4, 50);//���õ����и߶�Ϊ50
#pragma endregion

	for (int i = 0; i < 80; i++)
	{
		ui.TK->setItem(i, 0, new QTableWidgetItem("I" + QString::number(i)));//����0�е�����
		ui.TK->setItem(i, 1, new QTableWidgetItem(""));
		ui.TK->setItem(i, 2, new QTableWidgetItem("I" + QString::number(i + 80)));//����0�е�����
		ui.TK->setItem(i, 3, new QTableWidgetItem(""));
	}
	for (int j = 0; j < 80; j++)
	{
		ui.TK->setItem(j, 4, new QTableWidgetItem("O" + QString::number(j)));
		ui.TK->setItem(j, 5, new QTableWidgetItem(""));
		ui.TK->setItem(j, 6, new QTableWidgetItem("O" + QString::number(j + 80)));
		ui.TK->setItem(j, 7, new QTableWidgetItem(""));
	}
	//bool InputStat[20] = { 0,1,1,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,0,0 };//����ѭ����ȡI/O
	//bool OutputStat[20] = { 0,1,1,0,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1 };

	//ushort nodeID = decimal.ToUInt16(nud_nodeID.Value);
	//for (int i = 0; i < 20; i++)//ѭ����ʾ�����ؼ�
	//{
	//	if (InputStat[i] == true)
	//	{
	//		ui.TK->item(i, 1)->setBackground(Qt::red);//���õ����е����б�����ɫΪ��
	//	}
	//	else
	//	{
	//		ui.TK->item(i, 1)->setBackground(Qt::white);
	//	}
	//	if (OutputStat[i] == true)
	//	{
	//		ui.TK->item(i, 3)->setBackground(Qt::red);//���õ����е����б�����ɫΪ��
	//	}
	//	else
	//	{
	//		ui.TK->item(i, 3)->setBackground(Qt::white);
	//	}
	//}
	ui.TK->show();
 }




