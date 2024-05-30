//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TPhone_directory *Phone_directory;
//---------------------------------------------------------------------------

__fastcall TPhone_directory::TPhone_directory(TComponent* Owner)
	: TForm(Owner)
{
}

//---------------------------------------------------------------------------

PhoneDirectory::~PhoneDirectory()
{
	Contact* current = head;
	while (current != nullptr)
	{
		Contact* next = current->next;
		delete current;
		current = next;
	}
}

//---------------------------------------------------------------------------

void PhoneDirectory::addContact(String name, String phone, String email)
{
	Contact* newContact = new Contact(name, phone, email);
	if (head == nullptr)
	{
		head = newContact;
	}
	else
	{
		Contact* current = head;
		while (current->next != nullptr)
		{
			current = current->next;
		}
		current->next = newContact;
	}
}

//---------------------------------------------------------------------------

void PhoneDirectory::getAllContacts(TListBox* listBox)
{
	listBox->Clear();
	Contact* current = head;
	while (current != nullptr)
	{
		String userInfo = "Name: " + current->name + ", Phone: " + current->phone + ", Email: " + current->email;
		listBox->Items->Add(userInfo);
		current = current->next;
	}
}

//---------------------------------------------------------------------------

void __fastcall TPhone_directory::savedatabtnClick(TObject *Sender)
{
	String name = nameedit->Text;
	String phone = phoneedit->Text;
	String email = emailedit->Text;

	phoneDirectory.addContact(name, phone, email);

	nameedit->Text = "";
	phoneedit->Text = "";
	emailedit->Text = "";
}

//---------------------------------------------------------------------------

void __fastcall TPhone_directory::showdatabtnClick(TObject *Sender)
{
    showing->Text = "Showing All Contacts";
	phoneDirectory.getAllContacts(ListBoxdata);
}

//---------------------------------------------------------------------------


void __fastcall TPhone_directory::ListBoxdataItemClick(TCustomListBox * const Sender,
          TListBoxItem * const Item)
{
	int index = Item->Index;
	ListBoxdata->Items->Delete(index);
}
//---------------------------------------------------------------------------



void __fastcall TPhone_directory::deletebtnClick(TObject *Sender)
{
    this->Close();
}
//---------------------------------------------------------------------------

void __fastcall TPhone_directory::Button1Click(TObject *Sender)
{
      showing->Text = "Click Any Contact To Delete";
}
//---------------------------------------------------------------------------

