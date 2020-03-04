/*Author :		1. นายกิตติกรณ์  บรรจงปรุ
				2. นายยุทธศาสตร์  นอขุนทด
				3. นายปกรณ์ ถาวรสันต์
Code :			1. 59172110122-0
				2. 59172110214-1
				3. 59172110223-9
Section :		CPE.59241
Lab No. :		Lab Sort_2559 (ข้อ 20)
Course :		04-061-212 Data Structures and Algorithms Laboratory
Due Date :		18/3/2561
Instruction :	A. Supattra Kerdmec
Description :	เพื่อได้ศึกษาอัลกอริทึมของฟังก์ชัน Sort แบบต่างๆ
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void Sorting_Char(vector<string> Data, int n); //ประกาศฟังก์ชัน Sorting_Char ใช้ในการ Sort ข้อมูลประเภทอักขระ
void Sorting_Num(vector<int> Data, int n);		//ประกาศฟังก์ชัน Sorting_Num ใช้ในการ Sort ข้อมูลประเภทจำนวนเต็ม
void Openf();									//ประกาศฟังก์ชัน OpenF ใช้ในการเรียกเปิดไฟล์ที่จะทำการ Sort
void Savef();									//ประกาศฟังก์ชัน SaveF ใช้ในการบันทึกข้อมูลที่ทำการ Sort เรียบร้อยแล้ว
void Display();									//ประกาศฟังก์ชัน Display ใช้ในการแสดงผลข้อมูล
vector<string> DataC_Sort;						//ประกาศโครงสร้างข้อมูล vector ประเภท String ชือ DataC_Sort เก็บข้อมูลประเภทอักขระจากไฟล์ที่ทำการเปิด
vector<int> DataN_Sort;							//ประกาศโครงสร้างข้อมูล vector ประเภท int ชือ DataN_Sort เก็บข้อมูลประเภทจำนวนเต็มจากไฟล์ที่ทำการเปิด
string Name,Type;								//ประกาศตัวแปรชนิด String ชื่อ Name ใช้เก็บชื่อไฟล์ และตัวแปร Type ใช้เก็บประเภทข้อมูลในไฟล์
int Size_c = 0,Size_n=0;						//ประกาศตัวแปร Size_c นับจำนวนข้อมูลชนิดอักขระในไฟล์ และตัวแปร Size_n นับจำนวนข้อมูลชนิดจำนวนเต็มในไฟล์

int main(void)
{
	int Menu;									//ประกาศตัวแปร Menu เก็บทางเลือกแต่ละ memu

	cout << endl << "==========================" << endl;
	cout << "     Sorting Program	";
	cout << endl << "==========================" << endl;
	cout << "  1.Open Files." << endl;
	cout << "  2.Sorting Files." << endl;
	cout << "  3.Display Files." << endl;
	cout << "  4.Save Files." << endl;
	cout << "  5.Exit Program." ;
	cout << endl << "==========================" << endl;
	do
	{
		cout << "Select Your Menu : ";			
		cin >> Menu;										//รับหมายเลข menu
		switch (Menu)										//ตรวจสอบว่าตัวแปร Menu ที่รับค่ามา คือ menu ไหน
		{
			case 1: Openf(); break;							//ถ้า Menu เป็น 1 ให้เรียกใช้ฟังก์ชัน Openf เพื่อเปิดไฟล์
			case 2: if (Type == "C")Sorting_Char(DataC_Sort, Size_c); else Sorting_Num(DataN_Sort, Size_n); break; //ถ้า Menu เป็น 2 ให้ตรวจสอบว่าไฟล์ที่ทำการเปิดเป็นประเภทไหนแล้วเรียกใช้ฟังก์ชัน Sort ตามประเภทไฟล์
			case 3: Display(); break;						//ถ้า Menu เป็น 3 ให้เรียกใช้ฟังก์ชัน Display เพื่อแสดงข้อมูล
			case 4: Savef(); break;							//ถ้า Menu เป็น 4 ให้เรียกใช้ฟังก์ชัน Savef เพื่อบันทึกข้อมูลลงในไฟล์
			case 5: cout << "==========================" << endl << " ...See You Again Bye..." << endl << "==========================" << endl; exit(0); break;
			default: cout << "Please Select Menu 1-5 !" << endl; break;
		}

	} while (Menu != 5);	//ถ้า Menu ที่รับมาไม่ใช่ menu ที่  5 ให้วนกลับไปป้อน Menu ใหม่ (วนไปรับค่า menu ใหม่จนกว่าเลือก menu exit)
}

void Openf() //ฟังก์ชัน OpenF ใช้ในการเรียกเปิดไฟล์ที่จะทำการ Sort
{
	int Choice,Choice2,dataN,i=0;			
	string dataC;
	
	cout << "==========================" << endl;
	cout << "....Select File...." << endl;
	cout << " 1.Char.txt" << endl;
	cout << " 2.Number.txt" << endl;
	cout << " 3.Other" << endl;

	do
	{
		cout << "Select Your Choice : ";
		cin >> Choice;							//รับค่าตัวเลือกที่เลือกเก็บไว้ใน choice
		switch (Choice)							//ตรวจสอบ choice ที่รับค่ามาว่าเป็น Choice ไหน
		{
			case 1: Name = "Char.txt"; Type = "C"; break;		//ถ้า choice เป็น 1 กำหนดให้ ชื่อของไฟล์ชื่อ Char.txt และเป็นประเภทอักขระ
			case 2: Name = "Number.txt"; Type = "N"; break;		//ถ้า choice เป็น 2 กำหนดให้ ชื่อของไฟล์ชื่อ Number.txt และเป็นประเภทจำนวนเต็ม
			case 3: cout << "Input Your File Name : ";			//ถ้า choice เป็น 3 กำหนดให้ ป้อนชื่อไฟล์เอง
					cin >> Name;								//รับค่าชื่อไฟล์ เก็บไว้ใน Name
					cout << "==========================" << endl;
					cout << "..Select Your Type File.." << endl;
					cout << " 1.String" << endl;
					cout << " 2.Number" << endl;
					do
					{
						cout << "Select Your Choice : ";		
						cin >> Choice2;							//รับค่าตัวเลือกที่เลือก ประเภทของไฟล์ เก็บไว้ในตัวแปร Choice2
						switch (Choice2)						//ตรวจสอบ Choice2 ที่รับมาว่าเป็น Choice ไหน
						{
						case 1: Type = "C"; break;				//ถ้า choice2 เป็น 1 กำหนดให้ประเภทไฟล์เป็นประเภทอักขระ
						case 2: Type = "N"; break;				//ถ้า choice2 เป็น 2 กำหนดให้ประเภทไฟล์เป็นประเภทจำนวนเต็ม
						default: cout << "Please Select 1 or 2 !" << endl; break;
						}
					} while (Choice2!=1&&Choice2!=2);		//วนรอบรับค่า choice2 จนกว่าจะป้อนค่า choice2 ที่ถูกต้อง คือ 1 หรือ 2 (เลือก choice ที่กำหนดให้)
			break;
			default: cout << "Please Select 1 or 2 or 3 !" << endl; break;
		}
	} while (Choice!=1&&Choice!=2&&Choice!=3);	//วนรอบรับค่า choice จนกว่าจะป้อนค่า choice ที่ถูกต้อง คือ 1,2 หรือ 3 (เลือก choice ที่กำหนดให้)
	
	ifstream File(Name);			//ประกาศฟังก์ชันไฟล์ ชื่อ File โดยกำหนดชื่อไฟล์จากตัวแปร Name
	if (File.is_open())				//ถ้าเปิดไฟล์ได้
	{
		cout << "==========================" << endl;
		cout << "Open File successfully !" << endl;
		if (Name=="Char.txt"||Type=="C")			//ถ้าไฟล์ชื่อ Char.txt หรือ เป็นประเภทอักขระจริง
		{
			DataC_Sort.clear();						//ทำการเคลียโครงสร้างข้อมูล DataC_Sort
			Size_c = 0;								//กำหนดให้ตัวแปรนับจำนวนอักขระเท่ากับ 0
			while (!File.eof())						//เปิดไฟล์ไปจนกว่าจะอ่านข้อมูลในไฟล์หมด
			{
				File >> dataC;						//เก็บข็อมูลในไฟล์ลงในตัวแปร dataC
				DataC_Sort.push_back(dataC);		//เก็บข้อมูลลงในโครงสร้างข้อมูล DataC_Sort โดยส่งข้อมูลจากตัวแปร dataC
				Size_c++;							//ตัวแปรจำนวนอักขระในไฟล์ทำการบวกเพิ่ม
			}
		}
		else           //มิฉะนั้นแล้ว                            
		{
			DataN_Sort.clear();						//ทำการเคลียโครงสร้างข้อมูล DataN_Sort
			Size_n = 0;								//กำหนดให้ตัวแปรนับจำนวนจำนวนเต็มเท่ากับ 0
			while (!File.eof())						//เปิดไฟล์ไปจนกว่าจะอ่านข้อมูลในไฟล์หมด
			{
				File >> dataN;						//เก็บข็อมูลในไฟล์ลงในตัวแปร dataN
				DataN_Sort.push_back(dataN);		//เก็บข้อมูลลงในโครงสร้างข้อมูล DataN_Sort โดยส่งข้อมูลจากตัวแปร dataN
				Size_n++;							//ตัวแปรจำนวนจำนวนเต็มในไฟล์ทำการบวกเพิ่ม
			}
		}
		cout << "==========================" << endl;
	}
	else   //ถ้าไม่สามรถเปิดไฟล์ได้ให้แสดงข้อความ
	{
		cout << "==========================" << endl;
		cout << "Can't Open File" << endl;
		cout << "==========================" << endl;
	}
}

void Display()	//ฟังก์ชัน Display ทำการแสดงข้อมูลในไฟล์ 
{
	cout << "==========================" << endl;
	cout << "....Display File...." << endl;
	if (Name == "Char.txt" || Type == "C")			//ถ้าไฟล์ชื่อ Char.txt หรือ เป็นประเภทอักขระจริง
	{
		for (int i = 0; i < Size_c; i++)			//วนรอบตามจำนวนของข้อมูล
		{
			cout << DataC_Sort[i] << " ";			//แสดงอักขระทีถูกเก็บอยู่ในโครงสร้างข้อมูล DataC_Sort ในแต่ละช่อง
		}
		cout << endl << "==========================" << endl;
	}
	else   //มิฉะนั้นแล้ว
	{
		for (int i = 0; i < Size_n; i++)			//วนรอบตามจำนวนของข้อมูล
		{
			cout << DataN_Sort[i] << " ";			//แสดงจำนวนเต็มทีถูกเก็บอยู่ในโครงสร้างข้อมูล DataN_Sort ในแต่ละช่อง
		}
		cout << endl << "==========================" << endl;
	}
}

void Savef()	//ฟังก์ชัน Savef ทำการ Save ข้อมูลลงในไฟล์
{
	ofstream File(Name, std::ios::trunc);	//ประกาศฟังก์ชันไฟล์ ชื่อ Flie โดยกำหนดชื่อไฟล์จากตัวแปร Name และมีคุณสมบัติคือเขียนไฟล์ข้อมูลทับไฟล์เดิม
	if (File.is_open())		//ถ้าเปิดไฟล์ได้		
	{
		cout << "==========================" << endl;
		cout << "Save File successfully !" << endl;
		if (Name == "Char.txt" || Type == "C")		//ถ้าไฟล์ชื่อ Char.txt หรือ เป็นประเภทอักขระจริง
		{
			for (int i = 0; i < Size_c; i++)		//วนรอบตามจำนวนของข้อมูล
			{
				File << DataC_Sort[i] << " ";		//เขียนอักขระทีถูกเก็บอยู่ในโครงสร้างข้อมูล DataC_Sort ในแต่ละช่องลงในไฟล์ โดยขั้นด้วยช่องว่าง
			}
		}
		else	//มิฉะนั้นแล้ว
		{
			for (int i = 0; i < Size_n; i++)		//วนรอบตามจำนวนของข้อมูล
			{
				File << DataN_Sort[i] << " ";		//เขียนจำนวนทีถูกเก็บอยู่ในโครงสร้างข้อมูล DataN_Sort ในแต่ละช่องลงในไฟล์ โดยขั้นด้วยช่องว่าง
			}
		}
		cout << "==========================" << endl;
	}
	else   //ถ้าไม่สามรถเปิดไฟล์ได้ให้แสดงข้อความ
	{
		cout << "==========================" << endl;
		cout << "Can't Save File" << endl;
		cout << "==========================" << endl;
	}
}

void Sorting_Char(vector<string> Data, int n)	//ฟังก์ชัน Sorting_Char ใช้ Sort ข้อมูลประเภทอักขระ
{
	int i, j;
	string temp;
	
	int k = 1;		//กำหนดให้ตัวแปร K เท่ากับ 1 
	while (k <= n / 3) //วนรอบจนกว่า K จะมากกว่าจำนวนข้อมูลหาร 3
		k = k * 3 + 1;	//กำหนดให้ K หรือจำนวนที่ใช้แบ่งข้อมูล เท่ากับ K*3+1
	while (k > 0)	//วนรอบจนกว่า k จะน้อยกว่า 0 
	{
		for (i = k; i < n; i++)		//วนรอบไปจนกว่า K จะมากกว่าจำนวนข้อมูล
		{
			temp = Data[i];			//กำหนดให้ Temp มีค่าเท่ากับข้อมูลในช่องนั้นๆ
			j = i;					//กำหนดให้ j =  i 
			while (j > k - 1 && Data[j - k] >= temp)  //วนรอบเปรียบเทียบข้อมูลในแต่ละช่องเพื่อหาข้อมูลที่มากกว่า
			{
				Data[j] = Data[j - k];		//กำหนดให้ Data ช่องนั้นๆ เท่ากับ Data ช่องที่น้อยกว่า
				j -= k;			
			}
			Data[j] = temp;       //กำหนดให้ data ช่องนั้นๆ เท่ากับ temp
		}
		k = (k - 1) / 3; //ทำการลดค่าของ K 
	}
	DataC_Sort.clear();						//ทำการเคลียโครงสร้างข้อมูล DataC_Sort
	for (int i = 0; i < n; i++)				//วนรอบตามจำนวนของข้อมูล
	{
		DataC_Sort.push_back(Data[i]);		//เก็บข้อมูลที่ทำการ Sort เรียบร้อยแล้วลงใน โครงสร้างข้อมูล DataC_Sort โดยส่งค่าจากตัวแปร Data ในแต่ละช่อง
	}
}

void Sorting_Num(vector<int> Data, int n)		//ฟังก์ชัน Sorting_Number ใช้ Sort ข้อมูลประเภทจำนวนเต็ม
{
	int i, j, temp;
	
	int k = 1;		//กำหนดให้ตัวแปร K เท่ากับ 1 
	while (k <= n / 3)	//วนรอบจนกว่า K จะมากกว่าจำนวนข้อมูลหาร 3
		k = k * 3 + 1;	//กำหนดให้ K หรือจำนวนที่ใช้แบ่งข้อมูล เท่ากับ K*3+1
	while (k > 0) 
	{
		for (i = k; i < n; i++) //วนรอบไปจนกว่า K จะมากกว่าจำนวนข้อมูล
		{
			temp = Data[i];		//กำหนดให้ Temp มีค่าเท่ากับข้อมูลในช่องนั้นๆ
			j = i;				//กำหนดให้ j =  i
			while (j > k - 1 &&Data[j - k] >= temp)		//วนรอบเปรียบเทียบข้อมูลในแต่ละช่องเพื่อหาข้อมูลที่มากกว่า
			{
				Data[j] = Data[j - k];			//กำหนดให้ Data ช่องนั้นๆ เท่ากับ Data ช่องที่น้อยกว่า
				j -= k;
			}
			Data[j] = temp;				 //กำหนดให้ data ช่องนั้นๆ เท่ากับ temp
		}
		k = (k - 1) / 3; //ทำการลดค่าของ K 
	}
	DataN_Sort.clear();						//ทำการเคลียโครงสร้างข้อมูล DataN_Sort
	for (int i = 0; i < n; i++)				//วนรอบตามจำนวนของข้อมูล
	{
		DataN_Sort.push_back(Data[i]);		//เก็บข้อมูลที่ทำการ Sort เรียบร้อยแล้วลงใน โครงสร้างข้อมูล DataN_Sort โดยส่งค่าจากตัวแปร Data ในแต่ละช่อง
	}
}
