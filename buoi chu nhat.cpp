#include<iostream>
#include<conio.h>
using namespace std;
#define maxx 200

typedef struct member
{   int ID;
    char Name[255];
    int Age;
    int Group_id;
} member;

//global variables
member ListMembers[maxx];
int number_of_members=0;
member tmp;
//function
int add_member(member ListMembers[maxx]);
int delete_member(member ListMembers[maxx]);
int edit_member(member ListMembers[maxx]);
int find_member_by_id();
int find_member_by_age();
char *press_name();
int *press_age();
int *press_ID();
int *press_Group_id();


//============== MAIN =======================================================================================
int main()
{
    int choice;
    int yesno=1;
    cout<<"\n";
    cout<<" ********************* MENU **********************"<<endl;
    cout<<" |    Them thong tin 1 thanh vien :           1  |"<<endl;
    cout<<" |    Xoa thong tin 1 thanh vien  :           2  |"<<endl;
    cout<<" |    Sua thong tin 1 thanh vien  :           3  |"<<endl;
    cout<<" |    Tim thong tin thanh vien bang ID :      4  |"<<endl;
    cout<<" |    Tim thong tin thanh vien bang tuoi :    5  |"<<endl;
    cout<<" |    Tim thong tin thanh vien bang ten nhom: 6  |"<<endl;
    cout<<" |    In ra danh sach thanh vien :            7  |"<<endl;
    cout<<" *************************************************"<<endl;
    while(yesno==1)
    {
        cout<<"\n Chon chuc nang: ";
        cin>>choice;
        if(choice<1||choice>7)
        {   cout<<" Ban hay nhap lai: ";
            cin>>choice;
        }
        switch (choice)
        {
            case 1:
                add_member(ListMembers);
                break;
            case 2:
                delete_member(ListMembers);
                break;
            case 3:
                edit_member(ListMembers);
                break;



        }
        cout<<"\n>> Ban muon su dung tiep? 1/0 : ";
        cin>>yesno;
    }
    return 0;
}

//================= Hàm thêm tên =========================================================================
char *press_name()
{   cout<<"Name: ";
    cin>>tmp.Name;
    return tmp.Name;//thắc mắc? sao chỗ này không cần thêm toán tử &
}

//================= Hàm thêm tuổi ========================================================================
int *press_age()
{   cout<<"Age: ";
    cin>>tmp.Age;
    return &tmp.Age;
}

//================= Hàm thêm ID ==========================================================================
int *press_ID()
{   cout<<"ID: ";
    cin>>tmp.ID;
    return &tmp.ID;
}
//================= Hàm thêm nhóm ========================================================================
int *press_Group_id()
{   cout<<"Group_id: ";
    cin>>tmp.Group_id;
    return &tmp.Group_id;
}

//================= Hàm thêm thành viên =================================================================
int add_member(member ListMembers[maxx])// về tách riêng các hàm nhập tên,id,age,...
{
    cout<<"---------------------------------------------------------------"<<endl;
    cout<<"\n>> So thanh vien da co trong danh sach: "<<number_of_members<<endl;
    int i,yes_no;

    for(i= number_of_members;i<maxx;i++)
    {   cout<<">> Nhap thong tin thanh vien:"<<endl;
        press_ID();
        press_name();
        press_age();
        press_Group_id();
        ListMembers[i]=tmp;
        number_of_members++;//khi nhập xong người thứ 1=a[0] thì number=1
                            //khi nhập xong người thứ 2=a[1] thì number=2
                            //nên number chính là số thành viên đã có trong danh sách
                            //lần thêm thông tin tiếp theo bắt đầu từ a[number]

        cout<<">> Do you want to enter info again? "<<"1/0: ";
        cin>>yes_no;
        if(yes_no==0) break;
    }
    cout<<">> So thanh vien hien tai trong danh sach: "<<number_of_members<<endl;
    return number_of_members;
}

//================== Hàm tìm thành viên bằng ID ========================================================
int find_member_by_id()
{
    int id;
    int yes_no=1;
    while(yes_no==1)
    {
        cout<<"---------------------------------------------------------------"<<endl;
        cout<<"\n>> Nhap ID can tim: ";
        cin>>id;
        for(int i=0;i<number_of_members;i++)
            if(ListMembers[i].ID==id)
            {
                cout<<">> Thanh vien can tim la: "<<endl;
                cout<<"ID: "<<ListMembers[i].ID<<endl;
                cout<<"Name: "<<ListMembers[i].Name<<endl;
                cout<<"Group: "<<ListMembers[i].Group_id<<endl;
                cout<<"Age: "<<ListMembers[i].Age<<endl;
                return i;
            }
        cout<<">> Khong ton tai thanh vien co ID="<<id<<endl;
        cout<<">> Do you want to find a member by ID again? "<<"1/0: ";
        cin>>yes_no;
        if(yes_no==0) return -1;
    }
}

//================== Hàm tìm thành viên bằng tuổi =========================
int find_member_by_age()
{
    int age;
    int dem=0;
    int yes_no=1;

    while(yes_no==1)
    {
        cout<<"---------------------------------------------------------------"<<endl;
        cout<<"\n>> Nhap tuoi can tim: ";
        cin>>age;
        for(int i=0;i<number_of_members;i++)
            if(ListMembers[i].Age==age)
            {
                dem++;
                cout<<"\nThanh vien thu "<<dem<<"tim duoc la: "<<endl;
                cout<<"ID: "<<ListMembers[i].ID<<endl;
                cout<<"Name: "<<ListMembers[i].Name<<endl;
                cout<<"Group: "<<ListMembers[i].Group_id<<endl;
                cout<<"Age: "<<ListMembers[i].Age<<endl;
            }
        if(dem==0)
            cout<<">> Khong ton tai thanh vien co tuoi ="<<age<<endl;
        cout<<">> Do you want to find a member by Age again? "<<"1/0: ";
        cin>>yes_no;
    }
}

//===================== Hàm Xóa thông tin 1 thành viên ==================================================
int delete_member(member ListMembers[maxx])
{
    int id,yn;
    int i=find_member_by_id();
    if(i==-1)
    {
        cout<<">> Khong thuc hien xoa!"<<endl;
        return number_of_members;
    }
    cout<<">> Ban muon xoa thanh vien nay? 1/0 : ";
    cin>>yn;
    if(yn==1)
    {
        for(;i<number_of_members-1;i++)
            ListMembers[i]=ListMembers[i+1];
        number_of_members--;
        cout<<">> Xoa thanh cong!"<<endl;
    }
    else if(yn==0)
        cout<<">> Khong thuc hien xoa!"<<endl;

    return number_of_members;

}

//================== Hàm Sửa thông tin thành viên ======================================================
int edit_member(member ListMembers[maxx])
{
    int id,yn;
    int i=find_member_by_id();
    if(i==-1)
    {
        cout<<">> Khong thuc hien edit!"<<endl;
        return -1;
    }
    cout<<">> Ban muon sua thong tin cua thanh vien nay? 1/0 : ";
    cin>>yn;
    if(yn==1)
    {
        press_ID();
        press_name();
        press_age();
        press_Group_id();
        ListMembers[i]=tmp;
        cout<<">> Sua thanh cong!"<<endl;
        return i;
    }
    else if(yn==0)
    {   cout<<">> Khong thuc hien edit!"<<endl;
        return -1;
    }

}
