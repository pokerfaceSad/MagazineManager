#include<iostream> 
#include<cstring>
#include<set>
using namespace std;

/*
*
*	�û��� 
* 
*/ 
class User{
	
	public:
		string name; //���� 
		bool sex; //�Ա�TRUE--Ů  FALSE--�У� 
		int id; //��� 
		string tele; //�绰���� 
		string time; //�������� 
//		string magazineUnit; //��־��λ
		int subscriptionNum; //������
//		User(string _name,bool _sex,int _id,string _tele,string _time,string _magazineUnit,int _subscriptionNum);
		User(string _name,bool _sex,int _id,string _tele,string _time,int _subscriptionNum);
		string getName(){return this->name;}	

		bool operator< (const User& p) const
		{
		        if (id<p.id)
		                return true;
		        else
		                return false;
		}
		bool operator== (const User& other)
		{
			return (id == other.id);
		}
};
//������������ 
ostream& operator << (ostream& out,const User& p){
	string _sex;
	if(p.sex) _sex = "Ů";
	else _sex = "��";	
    out << "ID:"<< p.id <<"	������" << p.name << "	�Ա�:" << _sex << "		�绰���룺" << p.tele << "		�������ޣ�" << p.time << endl; 
    return out;
}

//���幹�췽�� 
//User::User(string _name,bool _sex,int _id,string _tele,string _time,string _magazineUnit,int _subscriptionNum){
User::User(string _name,bool _sex,int _id,string _tele,string _time,int _subscriptionNum){
	
	name = _name;	
	id = _id;
	sex = _sex;
	tele = _tele;
	time = _time;
//	magazineUnit = _magazineUnit;
	subscriptionNum = _subscriptionNum;
	
}
//��װ���췽�� 
User creatUser(){
	string name; //���� 
	cout << "�������û�������" << endl; 
	cin >> name;
	bool sex = true; //�Ա�TRUE--Ů  FALSE--�У�
	cout << "�������û��Ա���/Ů����" << endl; 
	while(true)
	{
	 	string _sex;
		cin >> _sex;
		if(_sex == "��" ) {
			sex = false;	
			break;
		}else if(_sex == "Ů"){
			sex = true;	
			break;
		}else cout << "�밴����ʾ���룺" << endl; 
	} 
	
	int id = 0; //��� 
	string tele = "12456"; //�绰����
	cout << "�������û��绰���룺" << endl; 
	cin >> tele;
	string time; //�������� 
	cout << "�����붩��������ݣ�" << endl;
	string temp; 
	cin >> temp;
	time = temp + "��"; 
	cout << "�����붩�������·ݣ�" << endl;
	cin >> temp;
	time = time + temp + "��";
	
//	string magazineUnit = Magazine::name; //��־��λ
	int subscriptionNum = 10; //������
	cout << "�����붩������" << endl;
	cin >> subscriptionNum; 
//	User user(name,sex,id,tele,time,magazineUnit,subscriptionNum);
	User user(name,sex,id,tele,time,subscriptionNum);
	
	return user;
}



/*
*
* ��־�� 
*
*/
class Magazine{
	
	public: 
		static string name;
		set<User> userSet;
		int getNewId();	
		void showUser(); 
		void addUser(); 
		void editUser();
		void deleteUser(); 
		void searchUser();
		void statisticsUser(); 
	
};
string Magazine::name = "����";
void Magazine::showUser(){
	
	int num = 0;
	cout << "-------�û���Ϣ--------" << endl;
	for(set<User>::iterator it = userSet.begin() ; it!=userSet.end() ; it++)
	{
		num++;
		cout << *it << endl;
	}
	
	cout << "��" << num << "���û�" <<endl; 
}
int Magazine::getNewId(){
	int id;
	for(set<User>::iterator it = userSet.begin();it!=userSet.end();it++)
	{
		 id = id > (*it).id ? id : (*it).id;
	}
		 
	return id+1;
}
void Magazine::addUser(){
	User user = creatUser();
	user.id = getNewId();
	userSet.insert(user);
	cout << "���Id:"<< user.id <<"�û��ɹ�" << endl; 
} 
 
void Magazine::editUser(){
	int id;
	cout << "������Ҫ�޸���Ϣ�û���ID" << endl;
	cin >> id;
	set<User>::iterator it;
	for(it = userSet.begin() ;it!=userSet.end(); it++) 
	{
		if((*it).id == id) break; 
	}
	User user(*it);
	userSet.erase(it);
	cout << "������Ҫ�޸ĵ���Ϣ���" << endl;
	int i;
	cout << "1.����\n2.�Ա�\n3.�绰����\n4.��������\n5.������\n6.�˳�\n"  ;
	cin >> i;
	int flag = 1;
	while(flag)
	{
		switch(i)
		{
			case 1: 
			{
					string _name;
					cout << "�������û�������" << endl; 
					cin >> _name;
					user.name = _name;
					flag = 0; 
					
					break;
			}
			case 2: 
			{
					bool __sex = true; 
					cout << "�������û��Ա���/Ů����" << endl; 
					while(true)
					{
					 	string _sex;
						cin >> _sex;
						if(_sex == "��" ) {
							__sex = false;	
							break;
						}else if(_sex == "Ů"){
							__sex = true;	
							break;
						}else cout << "�밴����ʾ���룺" << endl; 
					} 
					user.sex = __sex;
					flag = 0; 
					break;
			}
			case 3: 
			{
					cout << "�������û��绰���룺" << endl; 
					cin >> user.tele;
					flag = 0; 
					break;	
			}		
			case 4: 
			{
					string time; //�������� 
					cout << "�����붩��������ݣ�" << endl;
					string temp; 
					cin >> temp;
					time = temp + "��"; 
					cout << "�����붩�������·ݣ�" << endl;
					cin >> temp;
					time = time + temp + "��";
					user.time = time;
					flag = 0; 
					break;
			}
			case 5: 
			{
					cout << "�����붩������" << endl;
					cin >> user.subscriptionNum; 
					flag = 0; 
					break;
			}
			case 6: flag = 0;break; 
			default:
					cout << "�ޱ�Ŷ�Ӧ��Ϣ" << endl;
		} 
		userSet.insert(user);
	}	
	cout << "�޸����" << endl; 
	
}
 
void Magazine::deleteUser(){
	int id;
	cout << "������Ҫɾ���û���ID" << endl;
	cin >> id;
	set<User>::iterator it;
	for(it = userSet.begin() ;it!=userSet.end(); it++) 
	{
		if((*it).id == id) break; 
	}
	userSet.erase(it);
	cout << "ɾ���ɹ�" << endl;
}

void Magazine::searchUser(){
	
	cout << "������Ҫ��ѯ���ֶ�" << endl;
	cout << "1.����\n2.�Ա�\n3.�绰����\n4.�˳�\n"; 
	int order;
	cin >> order;
	switch(order)
	{
		case 1:{
			string name;
			cout << "����������" << endl ;
			cin >> name; 
			int num = 0; 
			for(set<User>::iterator it = userSet.begin();it!=userSet.end();it++)
			{
				if((*it).name == name) 
				{
					cout << *it << endl;
					num++;
				}
			}
			if(num!=0) cout << "��"<< num <<"����¼" << endl; 
			else cout << "�޽��" << endl; 
			
			break;
		}
		case 2:{
			string _sex;
			cout << "�������Ա���/Ů��" << endl ;
			int flag = 1;
			bool sex = false;
			while(1) 
			{
				cin >> _sex;
				if(_sex == "Ů") {
					sex = false;	
					break; 
				} 
				else if(_sex == "��")
				{
					sex = true;
					break;
				} 
				else cout << "�밴����ʾ����" << endl;
			}
			int num = 0; 
			for(set<User>::iterator it = userSet.begin();it!=userSet.end();it++)
			{
				if((*it).sex == sex) 
				{
					cout << *it << endl;
					num++;
				}
			}
			if(num!=0) cout << "��"<< num <<"����¼" << endl; 
			else cout << "�޽��" << endl; 
			
			break;
		}
		case 3:{
			string tele;
			cout << "������绰����" << endl ;
			cin >> tele; 
			int num = 0; 
			for(set<User>::iterator it = userSet.begin();it!=userSet.end();it++)
			{
				if((*it).tele == tele) 
				{
					cout << *it << endl;
					num++;
				}
			}
			if(num!=0) cout << "��"<< num <<"����¼" << endl; 
			else cout << "�޽��" << endl; 
			break;
		}
		case 4:{
			return;
		}
		default:{
			break;
		} 
	}
	
}
void Magazine::statisticsUser(){
	int man = 0;
	int woman = 0;
	for(set<User>::iterator it = userSet.begin();it!=userSet.end();it++)
	{
		if((*it).sex) woman++;
		else man++;
	}
	cout << "�û�����������" << man << endl <<  "�û�Ů��������" << woman << endl;
}

int main(){
	
	Magazine m = Magazine();
	User user1("������",false,1,"110","2018��12��",100);
	User user2("������",false,2,"119","2017��12��",500);
	User user3("Daisy",true,3,"120","2018��10��",200);
	m.userSet.insert(user1);
	m.userSet.insert(user2);
	m.userSet.insert(user3);
	bool flag = true;
	while(flag)
	{
		char order;
		cout <<"��"<< Magazine::name << "��" << "��־����ϵͳ\n\n"; 
		cout << "1.�����¶���\n2.��ʾ�����û���Ϣ\n3.�༭�û���Ϣ\n4.ɾ���û�\n5.�����û�\n6.ͳ���û���Ϣ\n7.�˳�\n";
		fflush(stdin);
		switch(order = getchar())
		{
			case '1':{
				m.addUser();
				break;
			}
			case '2':{
				m.showUser();
				break; 
			}
			case '3':{
				m.editUser();
				break; 
			}
			case '4':{
				m.deleteUser();
				break; 
			}
			case '5':{
				m.searchUser();
				break;
			}
			case '6':{
				m.statisticsUser(); 
				break;
			}
			case '7':{
				return 0;
			}
			default:{
				cout << "��������ȷ���" << endl; 
				break;
			}
		}
		system("pause");
		system("cls"); 
	}
	return 0;
}
