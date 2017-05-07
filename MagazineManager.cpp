#include<iostream> 
#include<cstring>
#include<set>
using namespace std;

/*
*
*	用户类 
* 
*/ 
class User{
	
	public:
		string name; //姓名 
		bool sex; //性别（TRUE--女  FALSE--男） 
		int id; //编号 
		string tele; //电话号码 
		string time; //订阅期限 
//		string magazineUnit; //杂志单位
		int subscriptionNum; //订阅数
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
//重载输出运算符 
ostream& operator << (ostream& out,const User& p){
	string _sex;
	if(p.sex) _sex = "女";
	else _sex = "男";	
    out << "ID:"<< p.id <<"	姓名：" << p.name << "	性别:" << _sex << "		电话号码：" << p.tele << "		订阅期限：" << p.time << endl; 
    return out;
}

//定义构造方法 
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
//封装构造方法 
User creatUser(){
	string name; //姓名 
	cout << "请输入用户姓名：" << endl; 
	cin >> name;
	bool sex = true; //性别（TRUE--女  FALSE--男）
	cout << "请输入用户性别（男/女）：" << endl; 
	while(true)
	{
	 	string _sex;
		cin >> _sex;
		if(_sex == "男" ) {
			sex = false;	
			break;
		}else if(_sex == "女"){
			sex = true;	
			break;
		}else cout << "请按照提示输入：" << endl; 
	} 
	
	int id = 0; //编号 
	string tele = "12456"; //电话号码
	cout << "请输入用户电话号码：" << endl; 
	cin >> tele;
	string time; //订阅期限 
	cout << "请输入订阅期限年份：" << endl;
	string temp; 
	cin >> temp;
	time = temp + "年"; 
	cout << "请输入订阅期限月份：" << endl;
	cin >> temp;
	time = time + temp + "月";
	
//	string magazineUnit = Magazine::name; //杂志单位
	int subscriptionNum = 10; //订阅数
	cout << "请输入订阅数：" << endl;
	cin >> subscriptionNum; 
//	User user(name,sex,id,tele,time,magazineUnit,subscriptionNum);
	User user(name,sex,id,tele,time,subscriptionNum);
	
	return user;
}



/*
*
* 杂志类 
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
string Magazine::name = "读者";
void Magazine::showUser(){
	
	int num = 0;
	cout << "-------用户信息--------" << endl;
	for(set<User>::iterator it = userSet.begin() ; it!=userSet.end() ; it++)
	{
		num++;
		cout << *it << endl;
	}
	
	cout << "共" << num << "个用户" <<endl; 
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
	cout << "添加Id:"<< user.id <<"用户成功" << endl; 
} 
 
void Magazine::editUser(){
	int id;
	cout << "请输入要修改信息用户的ID" << endl;
	cin >> id;
	set<User>::iterator it;
	for(it = userSet.begin() ;it!=userSet.end(); it++) 
	{
		if((*it).id == id) break; 
	}
	User user(*it);
	userSet.erase(it);
	cout << "请输入要修改的信息编号" << endl;
	int i;
	cout << "1.姓名\n2.性别\n3.电话号码\n4.订阅期限\n5.订阅数\n6.退出\n"  ;
	cin >> i;
	int flag = 1;
	while(flag)
	{
		switch(i)
		{
			case 1: 
			{
					string _name;
					cout << "请输入用户姓名：" << endl; 
					cin >> _name;
					user.name = _name;
					flag = 0; 
					
					break;
			}
			case 2: 
			{
					bool __sex = true; 
					cout << "请输入用户性别（男/女）：" << endl; 
					while(true)
					{
					 	string _sex;
						cin >> _sex;
						if(_sex == "男" ) {
							__sex = false;	
							break;
						}else if(_sex == "女"){
							__sex = true;	
							break;
						}else cout << "请按照提示输入：" << endl; 
					} 
					user.sex = __sex;
					flag = 0; 
					break;
			}
			case 3: 
			{
					cout << "请输入用户电话号码：" << endl; 
					cin >> user.tele;
					flag = 0; 
					break;	
			}		
			case 4: 
			{
					string time; //订阅期限 
					cout << "请输入订阅期限年份：" << endl;
					string temp; 
					cin >> temp;
					time = temp + "年"; 
					cout << "请输入订阅期限月份：" << endl;
					cin >> temp;
					time = time + temp + "月";
					user.time = time;
					flag = 0; 
					break;
			}
			case 5: 
			{
					cout << "请输入订阅数：" << endl;
					cin >> user.subscriptionNum; 
					flag = 0; 
					break;
			}
			case 6: flag = 0;break; 
			default:
					cout << "无编号对应信息" << endl;
		} 
		userSet.insert(user);
	}	
	cout << "修改完成" << endl; 
	
}
 
void Magazine::deleteUser(){
	int id;
	cout << "请输入要删除用户的ID" << endl;
	cin >> id;
	set<User>::iterator it;
	for(it = userSet.begin() ;it!=userSet.end(); it++) 
	{
		if((*it).id == id) break; 
	}
	userSet.erase(it);
	cout << "删除成功" << endl;
}

void Magazine::searchUser(){
	
	cout << "请输入要查询的字段" << endl;
	cout << "1.姓名\n2.性别\n3.电话号码\n4.退出\n"; 
	int order;
	cin >> order;
	switch(order)
	{
		case 1:{
			string name;
			cout << "请输入姓名" << endl ;
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
			if(num!=0) cout << "共"<< num <<"条记录" << endl; 
			else cout << "无结果" << endl; 
			
			break;
		}
		case 2:{
			string _sex;
			cout << "请输入性别（男/女）" << endl ;
			int flag = 1;
			bool sex = false;
			while(1) 
			{
				cin >> _sex;
				if(_sex == "女") {
					sex = false;	
					break; 
				} 
				else if(_sex == "男")
				{
					sex = true;
					break;
				} 
				else cout << "请按照提示输入" << endl;
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
			if(num!=0) cout << "共"<< num <<"条记录" << endl; 
			else cout << "无结果" << endl; 
			
			break;
		}
		case 3:{
			string tele;
			cout << "请输入电话号码" << endl ;
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
			if(num!=0) cout << "共"<< num <<"条记录" << endl; 
			else cout << "无结果" << endl; 
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
	cout << "用户男性人数：" << man << endl <<  "用户女性人数：" << woman << endl;
}

int main(){
	
	Magazine m = Magazine();
	User user1("吴彦祖",false,1,"110","2018年12月",100);
	User user2("王力宏",false,2,"119","2017年12月",500);
	User user3("Daisy",true,3,"120","2018年10月",200);
	m.userSet.insert(user1);
	m.userSet.insert(user2);
	m.userSet.insert(user3);
	bool flag = true;
	while(flag)
	{
		char order;
		cout <<"《"<< Magazine::name << "》" << "杂志管理系统\n\n"; 
		cout << "1.增加新订户\n2.显示所有用户信息\n3.编辑用户信息\n4.删除用户\n5.搜索用户\n6.统计用户信息\n7.退出\n";
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
				cout << "请输入正确编号" << endl; 
				break;
			}
		}
		system("pause");
		system("cls"); 
	}
	return 0;
}
