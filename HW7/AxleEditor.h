#pragma once
#include "Axle.h"
#include <msclr\marshal_cppstd.h>  //  needed for string conversions

namespace GearSimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AxleEditor
	/// </summary>
	public ref class AxleEditor : public System::Windows::Forms::Form
	{
	public:
		AxleEditor(Axle *anAxle) : AxleEditor()
		{
			theAxle = anAxle;
			resetAllBoxes();
		}
		AxleEditor(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AxleEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  startX_textBox;
	private: System::Windows::Forms::TextBox^  startY_textBox;
	private: System::Windows::Forms::TextBox^  startAngle_textBox;



	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label9;
	protected:
		Axle * theAxle;
	private: System::Windows::Forms::TextBox^  partID_textBox;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label5;
	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->startX_textBox = (gcnew System::Windows::Forms::TextBox());
			this->startY_textBox = (gcnew System::Windows::Forms::TextBox());
			this->startAngle_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->partID_textBox = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label1->Location = System::Drawing::Point(41, 69);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Start X";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label2->Location = System::Drawing::Point(40, 94);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 16);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Start Y";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label3->Location = System::Drawing::Point(14, 120);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(73, 16);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Start Angle";
			// 
			// startX_textBox
			// 
			this->startX_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startX_textBox->Location = System::Drawing::Point(92, 66);
			this->startX_textBox->Name = L"startX_textBox";
			this->startX_textBox->Size = System::Drawing::Size(87, 22);
			this->startX_textBox->TabIndex = 3;
			this->startX_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AxleEditor::startX_textBox_KeyDown);
			this->startX_textBox->LostFocus += gcnew System::EventHandler(this, &AxleEditor::startX_textBox_LostFocus);
			// 
			// startY_textBox
			// 
			this->startY_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->startY_textBox->Location = System::Drawing::Point(92, 91);
			this->startY_textBox->Name = L"startY_textBox";
			this->startY_textBox->Size = System::Drawing::Size(87, 22);
			this->startY_textBox->TabIndex = 4;
			this->startY_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AxleEditor::startY_textBox_KeyDown);
			this->startY_textBox->LostFocus += gcnew System::EventHandler(this, &AxleEditor::startY_textBox_LostFocus);
			// 
			// startAngle_textBox
			// 
			this->startAngle_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->startAngle_textBox->Location = System::Drawing::Point(92, 117);
			this->startAngle_textBox->Name = L"startAngle_textBox";
			this->startAngle_textBox->Size = System::Drawing::Size(87, 22);
			this->startAngle_textBox->TabIndex = 5;
			this->startAngle_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AxleEditor::startAngle_textBox_KeyDown);
			this->startAngle_textBox->LostFocus += gcnew System::EventHandler(this, &AxleEditor::startAngle_textBox_LostFocus);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label4->Location = System::Drawing::Point(185, 120);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(32, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"deg";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(12, 9);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(121, 24);
			this->label9->TabIndex = 21;
			this->label9->Text = L"Axle Editor";
			// 
			// partID_textBox
			// 
			this->partID_textBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->partID_textBox->Location = System::Drawing::Point(92, 38);
			this->partID_textBox->Name = L"partID_textBox";
			this->partID_textBox->Size = System::Drawing::Size(87, 22);
			this->partID_textBox->TabIndex = 23;
			this->partID_textBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &AxleEditor::partID_textBox_KeyDown);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ImageAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->label5->Location = System::Drawing::Point(41, 41);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(48, 16);
			this->label5->TabIndex = 22;
			this->label5->Text = L"Part ID";
			// 
			// AxleEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(309, 167);
			this->Controls->Add(this->partID_textBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->startAngle_textBox);
			this->Controls->Add(this->startY_textBox);
			this->Controls->Add(this->startX_textBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"AxleEditor";
			this->Text = L"AxleEditor";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &AxleEditor::AxleEditor_FormClosing);
			this->Load += gcnew System::EventHandler(this, &AxleEditor::AxleEditor_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void AxleEditor_Load(System::Object^  sender, System::EventArgs^  e) {

	}
	private: System::Void startX_textBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
			readStartX();
	}
	private: System::Void startY_textBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
			readStartY();
	}
	private: System::Void startAngle_textBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
			readStartAngle();
	}
	private: System::Void partID_textBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
			readPartID();
	}
	private: System::Void resetAllBoxes() {
		// resets all textboxes and labels to match current data in theAxle object
		if (theAxle != NULL) {
			startX_textBox->Text = Convert::ToString(theAxle->startX);
			startY_textBox->Text = Convert::ToString(theAxle->startY);
			startAngle_textBox->Text = Convert::ToString(theAxle->startAngle / (float)PI * 180.f);
			partID_textBox->Text = gcnew String(theAxle->partID.c_str());
		}
	}

	private: System::Void AxleEditor_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		readStartX();
		readStartY();
		readStartAngle();
		readPartID();
	}

	private: System::Void readStartX() {
		float theValue;

		try {
			theValue = (float)Convert::ToDecimal(startX_textBox->Text);
			theAxle->startX = theValue;

		}
		catch (Exception^ excep) {
			MessageBox::Show(this, "Value " + startX_textBox->Text + " could not be converted to decimal.\n "
				+ excep->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);

			//exit;   // <<<<<<<<<<possible exit from function
		}
	}
	private: System::Void readStartY() {
		float theValue;

		try {
			theValue = (float)Convert::ToDecimal(startY_textBox->Text);
			theAxle->startY = theValue;

		}
		catch (Exception^ excep) {
			MessageBox::Show(this, "Value " + startY_textBox->Text + " could not be converted to decimal.\n "
				+ excep->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);

			//exit;   // <<<<<<<<<<possible exit from function
		}

	}
	private: System::Void readStartAngle() {
		float theValue;

		try {
			theValue = (float)Convert::ToDecimal(startAngle_textBox->Text);
			// convert to radians before saving
			theAxle->startAngle = theValue * (float)PI / 180.f;

		}
		catch (Exception^ excep) {
			MessageBox::Show(this, "Value " + startAngle_textBox->Text + " could not be converted to decimal.\n "
				+ excep->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);

			//exit;   // <<<<<<<<<<possible exit from function
		}

	}
	private: System::Void readPartID() {
		msclr::interop::marshal_context context;
		std::string partID = context.marshal_as<std::string>(partID_textBox->Text);

		theAxle->partID = partID;
	}
	private: System::Void startX_textBox_LostFocus(System::Object^  sender, System::EventArgs^  e) {
		readStartX();
	}
	private: System::Void startY_textBox_LostFocus(System::Object^  sender, System::EventArgs^  e) {
		readStartY();
	}
	private: System::Void startAngle_textBox_LostFocus(System::Object^  sender, System::EventArgs^  e) {
		readStartAngle();
	}
	private: System::Void partID_textBox_LostFocus(System::Object^  sender, System::EventArgs^  e) {
		readPartID();
	}

	};

}
