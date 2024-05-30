#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Edit.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include <FMX.Layouts.hpp>
#include <FMX.ListBox.hpp>
#include <FMX.SearchBox.hpp>
#include <FMX.Graphics.hpp>
//---------------------------------------------------------------------------

class Contact {
public:
	String name;
	String phone;
	String email;
	Contact* next;

	Contact(String name, String phone, String email)
		: name(name), phone(phone), email(email), next(nullptr) {}
};

class PhoneDirectory {
private:
	Contact* head;
public:
	PhoneDirectory() : head(nullptr) {}
	~PhoneDirectory();

	void addContact(String name, String phone, String email);
	void getAllContacts(TListBox* listBox);
};

class TPhone_directory : public TForm
{
__published:
	TLabel *Label1;
	TEdit *nameedit;
	TLabel *Label2;
	TEdit *phoneedit;
	TLabel *Label3;
	TEdit *emailedit;
	TButton *savedatabtn;
	TListBox *ListBoxdata;
	TSearchBox *SearchBox1;
	TLabel *Label4;
	TButton *showdatabtn;
	TButton *deletebtn;
	TLabel *showing;
	TButton *Button1;
	void __fastcall savedatabtnClick(TObject *Sender);
	void __fastcall showdatabtnClick(TObject *Sender);
	void __fastcall ListBoxdataItemClick(TCustomListBox * const Sender, TListBoxItem * const Item);
	void __fastcall deletebtnClick(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);

private:
	PhoneDirectory phoneDirectory;
public:
	__fastcall TPhone_directory(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPhone_directory *Phone_directory;
//---------------------------------------------------------------------------
#endif

