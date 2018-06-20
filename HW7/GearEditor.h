#pragma once
#include <exception>
#include <iostream>
#include <fstream>
#include <string>
#include <msclr\marshal_cppstd.h>  //  needed for string conversions

// using flickerless panel makes the form design view not work.
// to use flickerless panel or allow the design view, use one of these
// in InitComponents() function
//    for design view >>>>    this->panel1 = (gcnew System::Windows::Forms::Panel());
//    for flickerless >>>>    this->panel1 = (gcnew FlickerLessPanel());


#include "FlickerLessPanel.h"

#include "Gear2D.h"

namespace GearEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for GearEditor
	/// </summary>
	public ref class GearEditor : public System::Windows::Forms::Form
	{
	public:
		GearEditor(Gear2D *aGear) : GearEditor()
		{
			if (theGear != NULL)
				delete theGear;
			theGear = aGear;
			resetAllBoxes();
		}

		GearEditor(void)
		{
			if (theGear == NULL)
				theGear = new Gear2D;
			mouseInPanel = false;
			panX = 300;
			panY = 300;
			zoomLevel = 60.0f;
			showTheGrid = false;
			drawAngle = 0;
			lastDiameter = 0.0;

			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			mouseInPanel = false;
			panX = currX = panel1->Width / 2;
			panY = currY = panel1->Height / 2;
			zoomLevel = 30.0f;

			lastDiameter = 0.0;

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~GearEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelFeedback;
	protected:

	private: System::Windows::Forms::Panel^  panel1;

	private: System::Windows::Forms::TextBox^  partIDtextBox;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  pitchTextBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::TextBox^  numbTeethTextBox;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  startXtextBox;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  startYtextBox;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::TextBox^  startAngleTextBox;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  pitchDiamLabel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		float lastDiameter;
		bool mouseInPanel;
		int panX;
		int panY;
		int currX, currY;
		float zoomLevel;
		Gear2D *theGear = NULL;
		bool showTheGrid;
		int drawAngle;

	private: System::Windows::Forms::Button^  loadFileButton;
	private: System::Windows::Forms::Button^  saveFileButton;
	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::HScrollBar^  rotateScrollBar;

	private: System::Windows::Forms::Label^  colorLabel;
	private: System::Windows::Forms::ComboBox^  axleComboBox;

	private: System::Windows::Forms::Label^  label12;

	private: System::Windows::Forms::TextBox^  planeTextBox;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->labelFeedback = (gcnew System::Windows::Forms::Label());
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->partIDtextBox = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->pitchTextBox = (gcnew System::Windows::Forms::TextBox());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->numbTeethTextBox = (gcnew System::Windows::Forms::TextBox());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->startXtextBox = (gcnew System::Windows::Forms::TextBox());
				 this->label5 = (gcnew System::Windows::Forms::Label());
				 this->label6 = (gcnew System::Windows::Forms::Label());
				 this->startYtextBox = (gcnew System::Windows::Forms::TextBox());
				 this->label7 = (gcnew System::Windows::Forms::Label());
				 this->startAngleTextBox = (gcnew System::Windows::Forms::TextBox());
				 this->label8 = (gcnew System::Windows::Forms::Label());
				 this->pitchDiamLabel = (gcnew System::Windows::Forms::Label());
				 this->loadFileButton = (gcnew System::Windows::Forms::Button());
				 this->saveFileButton = (gcnew System::Windows::Forms::Button());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->label11 = (gcnew System::Windows::Forms::Label());
				 this->planeTextBox = (gcnew System::Windows::Forms::TextBox());
				 this->rotateScrollBar = (gcnew System::Windows::Forms::HScrollBar());
				 this->colorLabel = (gcnew System::Windows::Forms::Label());
				 this->axleComboBox = (gcnew System::Windows::Forms::ComboBox());
				 this->label12 = (gcnew System::Windows::Forms::Label());
				 this->SuspendLayout();
				 // 
				 // labelFeedback
				 // 
				 this->labelFeedback->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
				 this->labelFeedback->AutoSize = true;
				 this->labelFeedback->Location = System::Drawing::Point(105, 463);
				 this->labelFeedback->Name = L"labelFeedback";
				 this->labelFeedback->Size = System::Drawing::Size(59, 13);
				 this->labelFeedback->TabIndex = 0;
				 this->labelFeedback->Text = L"nothing yet";
				 this->labelFeedback->TextAlign = System::Drawing::ContentAlignment::TopRight;
				 // 
				 // panel1
				 // 
				 this->panel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
					 | System::Windows::Forms::AnchorStyles::Left)
					 | System::Windows::Forms::AnchorStyles::Right));
				 this->panel1->AutoSize = true;
				 this->panel1->BackColor = System::Drawing::SystemColors::Window;
				 this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
				 this->panel1->Location = System::Drawing::Point(98, 41);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(536, 412);
				 this->panel1->TabIndex = 1;
				 this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GearEditor::panel1_Paint);
				 this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GearEditor::panel1_MouseClick);
				 this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GearEditor::panel1_MouseDown);
				 this->panel1->MouseEnter += gcnew System::EventHandler(this, &GearEditor::panel1_MouseEnter);
				 this->panel1->MouseLeave += gcnew System::EventHandler(this, &GearEditor::panel1_MouseLeave);
				 this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GearEditor::panel1_MouseMove);
				 // 
				 // partIDtextBox
				 // 
				 this->partIDtextBox->Location = System::Drawing::Point(4, 116);
				 this->partIDtextBox->Name = L"partIDtextBox";
				 this->partIDtextBox->Size = System::Drawing::Size(88, 20);
				 this->partIDtextBox->TabIndex = 3;
				 this->partIDtextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GearEditor::partIDtextBox_KeyDown);
				 this->partIDtextBox->LostFocus += gcnew System::EventHandler(this, &GearEditor::partIDtextBox_LostFocus);
				 this->partIDtextBox->MouseLeave += gcnew System::EventHandler(this, &GearEditor::textBox1_MouseLeave);
				 this->partIDtextBox->MouseHover += gcnew System::EventHandler(this, &GearEditor::gearIDtextBox_MouseHover);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(3, 102);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(40, 13);
				 this->label1->TabIndex = 4;
				 this->label1->Text = L"Part ID";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(3, 142);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(89, 13);
				 this->label2->TabIndex = 6;
				 this->label2->Text = L"Pitch (teeth/inch)";
				 // 
				 // pitchTextBox
				 // 
				 this->pitchTextBox->Location = System::Drawing::Point(4, 156);
				 this->pitchTextBox->Name = L"pitchTextBox";
				 this->pitchTextBox->Size = System::Drawing::Size(88, 20);
				 this->pitchTextBox->TabIndex = 5;
				 this->pitchTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GearEditor::pitchBox_KeyDown);
				 this->pitchTextBox->LostFocus += gcnew System::EventHandler(this, &GearEditor::pitchBox_LostFocus);
				 this->pitchTextBox->MouseLeave += gcnew System::EventHandler(this, &GearEditor::textBox1_MouseLeave);
				 this->pitchTextBox->MouseHover += gcnew System::EventHandler(this, &GearEditor::pitchTextBox_MouseHover);
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(3, 182);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(87, 13);
				 this->label3->TabIndex = 8;
				 this->label3->Text = L"Number of Teeth";
				 // 
				 // numbTeethTextBox
				 // 
				 this->numbTeethTextBox->Location = System::Drawing::Point(4, 196);
				 this->numbTeethTextBox->Name = L"numbTeethTextBox";
				 this->numbTeethTextBox->Size = System::Drawing::Size(88, 20);
				 this->numbTeethTextBox->TabIndex = 7;
				 this->numbTeethTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GearEditor::numbTeethTextBox_KeyDown);
				 this->numbTeethTextBox->LostFocus += gcnew System::EventHandler(this, &GearEditor::numbTeethTextBox_LostFocus);
				 this->numbTeethTextBox->MouseLeave += gcnew System::EventHandler(this, &GearEditor::textBox1_MouseLeave);
				 this->numbTeethTextBox->MouseHover += gcnew System::EventHandler(this, &GearEditor::numbTeethTextBox_MouseHover);
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(1, 299);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(73, 13);
				 this->label4->TabIndex = 10;
				 this->label4->Text = L"Start Location";
				 // 
				 // startXtextBox
				 // 
				 this->startXtextBox->Location = System::Drawing::Point(36, 316);
				 this->startXtextBox->Name = L"startXtextBox";
				 this->startXtextBox->Size = System::Drawing::Size(54, 20);
				 this->startXtextBox->TabIndex = 9;
				 this->startXtextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GearEditor::startXtextBox_KeyDown);
				 this->startXtextBox->LostFocus += gcnew System::EventHandler(this, &GearEditor::startXtextBox_LostFocus);
				 this->startXtextBox->MouseLeave += gcnew System::EventHandler(this, &GearEditor::textBox1_MouseLeave);
				 this->startXtextBox->MouseHover += gcnew System::EventHandler(this, &GearEditor::startXtextBox_MouseHover);
				 // 
				 // label5
				 // 
				 this->label5->AutoSize = true;
				 this->label5->Location = System::Drawing::Point(21, 319);
				 this->label5->Name = L"label5";
				 this->label5->Size = System::Drawing::Size(14, 13);
				 this->label5->TabIndex = 11;
				 this->label5->Text = L"X";
				 this->label5->TextAlign = System::Drawing::ContentAlignment::TopRight;
				 // 
				 // label6
				 // 
				 this->label6->AutoSize = true;
				 this->label6->Location = System::Drawing::Point(21, 340);
				 this->label6->Name = L"label6";
				 this->label6->Size = System::Drawing::Size(14, 13);
				 this->label6->TabIndex = 13;
				 this->label6->Text = L"Y";
				 this->label6->TextAlign = System::Drawing::ContentAlignment::TopRight;
				 // 
				 // startYtextBox
				 // 
				 this->startYtextBox->Location = System::Drawing::Point(36, 337);
				 this->startYtextBox->Name = L"startYtextBox";
				 this->startYtextBox->Size = System::Drawing::Size(54, 20);
				 this->startYtextBox->TabIndex = 12;
				 this->startYtextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GearEditor::startYtextBox_KeyDown);
				 this->startYtextBox->LostFocus += gcnew System::EventHandler(this, &GearEditor::startYtextBox_LostFocus);
				 this->startYtextBox->MouseLeave += gcnew System::EventHandler(this, &GearEditor::textBox1_MouseLeave);
				 this->startYtextBox->MouseHover += gcnew System::EventHandler(this, &GearEditor::startYtextBox_MouseHover);
				 // 
				 // label7
				 // 
				 this->label7->AutoSize = true;
				 this->label7->Location = System::Drawing::Point(1, 362);
				 this->label7->Name = L"label7";
				 this->label7->Size = System::Drawing::Size(34, 13);
				 this->label7->TabIndex = 15;
				 this->label7->Text = L"Angle";
				 this->label7->TextAlign = System::Drawing::ContentAlignment::TopRight;
				 // 
				 // startAngleTextBox
				 // 
				 this->startAngleTextBox->Location = System::Drawing::Point(36, 359);
				 this->startAngleTextBox->Name = L"startAngleTextBox";
				 this->startAngleTextBox->Size = System::Drawing::Size(54, 20);
				 this->startAngleTextBox->TabIndex = 14;
				 this->startAngleTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GearEditor::startAngletextBox_KeyDown);
				 this->startAngleTextBox->LostFocus += gcnew System::EventHandler(this, &GearEditor::startAngletextBox_LostFocus);
				 this->startAngleTextBox->MouseLeave += gcnew System::EventHandler(this, &GearEditor::textBox1_MouseLeave);
				 this->startAngleTextBox->MouseHover += gcnew System::EventHandler(this, &GearEditor::startAngleTextBox_MouseHover);
				 // 
				 // label8
				 // 
				 this->label8->AutoSize = true;
				 this->label8->Location = System::Drawing::Point(3, 222);
				 this->label8->Name = L"label8";
				 this->label8->Size = System::Drawing::Size(76, 13);
				 this->label8->TabIndex = 16;
				 this->label8->Text = L"Pitch Diameter";
				 // 
				 // pitchDiamLabel
				 // 
				 this->pitchDiamLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->pitchDiamLabel->Location = System::Drawing::Point(5, 236);
				 this->pitchDiamLabel->Name = L"pitchDiamLabel";
				 this->pitchDiamLabel->Size = System::Drawing::Size(87, 20);
				 this->pitchDiamLabel->TabIndex = 16;
				 this->pitchDiamLabel->Text = L"---";
				 this->pitchDiamLabel->MouseLeave += gcnew System::EventHandler(this, &GearEditor::textBox1_MouseLeave);
				 this->pitchDiamLabel->MouseHover += gcnew System::EventHandler(this, &GearEditor::pitchDiamLabel_MouseHover);
				 // 
				 // loadFileButton
				 // 
				 this->loadFileButton->Location = System::Drawing::Point(6, 41);
				 this->loadFileButton->Name = L"loadFileButton";
				 this->loadFileButton->Size = System::Drawing::Size(84, 23);
				 this->loadFileButton->TabIndex = 17;
				 this->loadFileButton->Text = L"Load Gear";
				 this->loadFileButton->UseVisualStyleBackColor = true;
				 this->loadFileButton->Click += gcnew System::EventHandler(this, &GearEditor::loadFileButton_Click);
				 this->loadFileButton->MouseLeave += gcnew System::EventHandler(this, &GearEditor::textBox1_MouseLeave);
				 this->loadFileButton->MouseHover += gcnew System::EventHandler(this, &GearEditor::loadFileButton_MouseHover);
				 // 
				 // saveFileButton
				 // 
				 this->saveFileButton->Location = System::Drawing::Point(6, 70);
				 this->saveFileButton->Name = L"saveFileButton";
				 this->saveFileButton->Size = System::Drawing::Size(84, 23);
				 this->saveFileButton->TabIndex = 18;
				 this->saveFileButton->Text = L"Save Gear";
				 this->saveFileButton->UseVisualStyleBackColor = true;
				 this->saveFileButton->Click += gcnew System::EventHandler(this, &GearEditor::saveFileButton_Click);
				 this->saveFileButton->MouseLeave += gcnew System::EventHandler(this, &GearEditor::textBox1_MouseLeave);
				 this->saveFileButton->MouseHover += gcnew System::EventHandler(this, &GearEditor::saveFileButton_MouseHover);
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
				 this->checkBox1->Appearance = System::Windows::Forms::Appearance::Button;
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->Location = System::Drawing::Point(571, 459);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(63, 23);
				 this->checkBox1->TabIndex = 19;
				 this->checkBox1->Text = L"ShowGrid";
				 this->checkBox1->UseVisualStyleBackColor = true;
				 this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &GearEditor::checkBox1_CheckedChanged);
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label9->Location = System::Drawing::Point(2, 9);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(127, 24);
				 this->label9->TabIndex = 20;
				 this->label9->Text = L"Gear Editor";
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label10->Location = System::Drawing::Point(585, 21);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(49, 15);
				 this->label10->TabIndex = 21;
				 this->label10->Text = L"(ng27)";
				 // 
				 // label11
				 // 
				 this->label11->AutoSize = true;
				 this->label11->Location = System::Drawing::Point(1, 262);
				 this->label11->Name = L"label11";
				 this->label11->Size = System::Drawing::Size(34, 13);
				 this->label11->TabIndex = 23;
				 this->label11->Text = L"Plane";
				 // 
				 // planeTextBox
				 // 
				 this->planeTextBox->Location = System::Drawing::Point(2, 276);
				 this->planeTextBox->Name = L"planeTextBox";
				 this->planeTextBox->Size = System::Drawing::Size(88, 20);
				 this->planeTextBox->TabIndex = 22;
				 this->planeTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &GearEditor::planeTextBox_KeyDown);
				 this->planeTextBox->LostFocus += gcnew System::EventHandler(this, &GearEditor::planeTextBox_LostFocus);
				 // 
				 // rotateScrollBar
				 // 
				 this->rotateScrollBar->Location = System::Drawing::Point(222, 22);
				 this->rotateScrollBar->Maximum = 360;
				 this->rotateScrollBar->Name = L"rotateScrollBar";
				 this->rotateScrollBar->Size = System::Drawing::Size(349, 13);
				 this->rotateScrollBar->TabIndex = 24;
				 this->rotateScrollBar->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &GearEditor::rotateScrollBar_Scroll);
				 // 
				 // colorLabel
				 // 
				 this->colorLabel->BackColor = System::Drawing::SystemColors::Highlight;
				 this->colorLabel->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
				 this->colorLabel->Location = System::Drawing::Point(3, 391);
				 this->colorLabel->Name = L"colorLabel";
				 this->colorLabel->Size = System::Drawing::Size(87, 20);
				 this->colorLabel->TabIndex = 26;
				 this->colorLabel->Text = L"Gear Color";
				 this->colorLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 this->colorLabel->Click += gcnew System::EventHandler(this, &GearEditor::colorLabel_Click);
				 // 
				 // axleComboBox
				 // 
				 this->axleComboBox->FormattingEnabled = true;
				 this->axleComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
					 L"Axle1", L"Axle2", L"Axle3", L"Axle4", L"Axle5",
						 L"Axle6", L"Axle7", L"Axle8", L"Axle9"
				 });
				 this->axleComboBox->Location = System::Drawing::Point(2, 432);
				 this->axleComboBox->Name = L"axleComboBox";
				 this->axleComboBox->Size = System::Drawing::Size(90, 21);
				 this->axleComboBox->TabIndex = 27;
				 // 
				 // label12
				 // 
				 this->label12->AutoSize = true;
				 this->label12->Location = System::Drawing::Point(2, 416);
				 this->label12->Name = L"label12";
				 this->label12->Size = System::Drawing::Size(27, 13);
				 this->label12->TabIndex = 28;
				 this->label12->Text = L"Axle";
				 // 
				 // GearEditor
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(646, 488);
				 this->Controls->Add(this->label12);
				 this->Controls->Add(this->axleComboBox);
				 this->Controls->Add(this->colorLabel);
				 this->Controls->Add(this->rotateScrollBar);
				 this->Controls->Add(this->label11);
				 this->Controls->Add(this->planeTextBox);
				 this->Controls->Add(this->label10);
				 this->Controls->Add(this->label9);
				 this->Controls->Add(this->checkBox1);
				 this->Controls->Add(this->saveFileButton);
				 this->Controls->Add(this->loadFileButton);
				 this->Controls->Add(this->pitchDiamLabel);
				 this->Controls->Add(this->label8);
				 this->Controls->Add(this->label7);
				 this->Controls->Add(this->startAngleTextBox);
				 this->Controls->Add(this->label6);
				 this->Controls->Add(this->startYtextBox);
				 this->Controls->Add(this->label5);
				 this->Controls->Add(this->label4);
				 this->Controls->Add(this->startXtextBox);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->numbTeethTextBox);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->pitchTextBox);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->partIDtextBox);
				 this->Controls->Add(this->panel1);
				 this->Controls->Add(this->labelFeedback);
				 this->Name = L"GearEditor";
				 this->Text = L"GearEditor";
				 this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &GearEditor::GearEditor_FormClosing);
				 this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &GearEditor::panel1_MouseWheel);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		Pen^ blackPen = gcnew Pen(Color::Black, 3.0f);
		Pen^ redPen = gcnew Pen(Color::Red, 3.0f);
		Pen^ bluePen = gcnew Pen(Color::Blue, 3.0f);
		Pen^ chosenPen = gcnew Pen(colorLabel->BackColor, 3.0f);

		float adj = 1000.;

		// still not happy with this translate since the panning is not working right.
		// I'll keep working on it :-(
		g->TranslateTransform((float)panX, (float)panY);

		g->ScaleTransform(zoomLevel / adj, -zoomLevel / adj);

		// show grid draws a space of 0.5-inch spacing, 50 inches around gear center
		if (showTheGrid)
			showGrid(g, 0.5f*adj, 50.f*adj, 50.f*adj);


		if (theGear->canCalculate()) {
			g->RotateTransform((float)drawAngle);
			chosenPen = gcnew Pen(theGear->getColor(), 3.0f);
			theGear->preview(g, chosenPen, adj);

			//int temp01 = chosenPen->Color->ARBG;
		}
		else
			labelFeedback->Text = "Enter pitch and number of teeth to preview gear";
	}
	private: void panel1_MouseDown(Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Middle)
			currX = e->X; currY = e->Y;

	}
	private: void panel1_MouseMove(Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (e->Button == System::Windows::Forms::MouseButtons::Middle) {
			panX += (e->X - currX);
			panY += (e->Y - currY);
			panel1->Refresh();
			currX = e->X; currY = e->Y; // need to constantly update to allow drag
		}
	}
	private: void showGrid(Graphics^ g, float spacing, float limitX, float limitY) {
		Pen^ grayPen = gcnew Pen(Color::LightSkyBlue, 0.1f);
		int i = 0;
		float currGridX = -limitX;
		float currGridY = -limitY;
		while (currGridX <= limitX) {
			g->DrawLine(grayPen, currGridX, -limitY, currGridX, limitY);
			g->DrawLine(grayPen, -limitX, currGridY, limitX, currGridY);
			currGridX += spacing;
			currGridY += spacing;
		}
	}
	private: System::Void textBox1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
	}

	private: System::Void partIDtextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
			readPartID();
	}
	private: System::Void pitchBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
			readPitch();
	}
	private: System::Void numbTeethTextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
			readNumbTeeth();
	}
	private: System::Void planeTextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
			readPlane();
	}
	private: System::Void startXtextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
			readStartX();
	}
	private: System::Void startYtextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
			readStartY();
	}
	private: System::Void startAngletextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter)
			readStartAngle();
	}

	private: System::Void partIDtextBox_LostFocus(System::Object^  sender, System::EventArgs^  e) {
		readPartID();
	}
	private: System::Void pitchBox_LostFocus(System::Object^  sender, System::EventArgs^  e) {
		readPitch();
	}
	private: System::Void numbTeethTextBox_LostFocus(System::Object^  sender, System::EventArgs^  e) {
		readNumbTeeth();
	}
	private: System::Void planeTextBox_LostFocus(System::Object^  sender, System::EventArgs^  e) {
		readPlane();
	}
	private: System::Void startXtextBox_LostFocus(System::Object^  sender, System::EventArgs^  e) {
		readStartX();
	}
	private: System::Void startYtextBox_LostFocus(System::Object^  sender, System::EventArgs^  e) {
		readStartY();
	}
	private: System::Void startAngletextBox_LostFocus(System::Object^  sender, System::EventArgs^  e) {
		readStartAngle();
	}

	private: System::Void readPartID() {
		msclr::interop::marshal_context context;

		std::string partID = context.marshal_as<std::string>(partIDtextBox->Text);

		theGear->setPartID(partID);

	}

	private: System::Void readPitch() {

		float pitch;

		try {
			pitch = (float)Convert::ToDecimal(pitchTextBox->Text);
			theGear->setPitch(pitch);

		}
		catch (Exception^ excep) {
			MessageBox::Show(this, "Value " + pitchTextBox->Text + " could not be converted to decimal.\n "
				+ excep->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);

			exit;   // <<<<<<<<<<possible exit from function
		}

		pitchDiamLabel->Text = Convert::ToString(theGear->getPitchDiam());
		panel1->Refresh();
	}

	private: System::Void readNumbTeeth() {
		int numbTeeth;

		try {
			numbTeeth = Convert::ToInt32(numbTeethTextBox->Text);
			theGear->setNumbTeeth(numbTeeth);
		}
		catch (Exception^ excep) {
			MessageBox::Show(this, "Value " + numbTeethTextBox->Text + " could not be converted to integer.\n "
				+ excep->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);

			exit;   // <<<<<<<<<<possible exit from function
		}

		pitchDiamLabel->Text = Convert::ToString(theGear->getPitchDiam());
		panel1->Refresh();
	}

	private: System::Void readPlane() {
		int plane;

		try {
			plane = Convert::ToInt32(planeTextBox->Text);
			theGear->setPlane(plane);
		}
		catch (Exception^ excep) {
			MessageBox::Show(this, "Value " + planeTextBox->Text + " could not be converted to integer.\n "
				+ excep->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);

			exit;   // <<<<<<<<<<possible exit from function
		}
	}

	private: System::Void readStartX() {
		float startValue;

		try {
			startValue = (float)Convert::ToDouble(startXtextBox->Text);
			theGear->setStartX(startValue);
		}
		catch (Exception^ excep) {
			MessageBox::Show(this, "Value " + startXtextBox->Text + " could not be converted to decimal.\n "
				+ excep->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);

			exit;   // <<<<<<<<<<possible exit from function
		}
	}

	private: System::Void readStartY() {
		float startValue;

		try {
			startValue = (float)Convert::ToDouble(startYtextBox->Text);
			theGear->setStartY(startValue);
		}
		catch (Exception^ excep) {
			MessageBox::Show(this, "Value " + startYtextBox->Text + " could not be converted to decimal.\n "
				+ excep->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);

			exit;   // <<<<<<<<<<possible exit from function
		}
	}

	private: System::Void readStartAngle() {
		float startValue;

		try {
			startValue = (float)Convert::ToDouble(startAngleTextBox->Text);
			theGear->setStartAngle(startValue);
		}
		catch (Exception^ excep) {
			MessageBox::Show(this, "Value " + startAngleTextBox->Text + " could not be converted to decimal.\n "
				+ excep->Message, "ERROR", MessageBoxButtons::OK, MessageBoxIcon::Error);

			exit;   // <<<<<<<<<<possible exit from function
		}
	}

	private: System::Void panel1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		labelFeedback->Text = "mouse click at " + e->X + ", " + e->Y;
	}
	private: System::Void textBox1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		labelFeedback->Text = "";
	}
	private: System::Void pitchDiamLabel_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		labelFeedback->Text = "Pitch Diameter is calculated based on pitch and number of teeth.";
	}

	private: System::Void numbTeethTextBox_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		labelFeedback->Text = "Enter number of teeth as an integer.";
	}
	private: System::Void pitchTextBox_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		labelFeedback->Text = "Pitch describes the spacing of teeth in teeth per inch.";
	}
	private: System::Void gearIDtextBox_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		labelFeedback->Text = "Gear ID helps identify the gear in lists and charts.";
	}
	private: System::Void startXtextBox_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		labelFeedback->Text = "Enter the X-coordinate of the gear's position at the start of the simulation.";
	}
	private: System::Void startYtextBox_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		labelFeedback->Text = "Enter the Y-coordinate of the gear's position at the start of the simulation.";
	}
	private: System::Void startAngleTextBox_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		labelFeedback->Text = "Enter the rotation angle of the gear at the start of the simulation.";
	}
	private: System::Void loadFileButton_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		labelFeedback->Text = "Load a pre-saved gear from a file.";
	}
	private: System::Void saveFileButton_MouseHover(System::Object^  sender, System::EventArgs^  e) {
		labelFeedback->Text = "Save the properties of the current gear into a file.";
	}
	private: System::Void panel1_MouseEnter(System::Object^  sender, System::EventArgs^  e) {
		mouseInPanel = true;
	}
	private: System::Void panel1_MouseLeave(System::Object^  sender, System::EventArgs^  e) {
		mouseInPanel = false;
	}
	private: System::Void loadFileButton_Click(System::Object^  sender, System::EventArgs^  e) {

		IO::Stream^ myStream;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = ".";  // current folder
		openFileDialog1->Filter = "gear files (*.gear)|*.gear|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 1;  // will show only gear files, but user can choose to show all files
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			using namespace std;

			if ((myStream = openFileDialog1->OpenFile()) != nullptr)
			{
				labelFeedback->Text = "Opening file: " + openFileDialog1->FileName;
				//System::Windows::Forms::MessageBox::Show(this, "Just a small pause", "PAUSE");

				myStream->Close();
				delete myStream;

				ifstream inFile;

				// need to convert String^ that comes from file dialog to regular string
				msclr::interop::marshal_context context;
				std::string standardString = context.marshal_as<std::string>(openFileDialog1->FileName);
				inFile.open(standardString);
				if (inFile.is_open()) {
					//delete theGear;
					//theGear = new Gear2D(inFile);

					theGear->readFile(inFile);
					inFile.close();
					resetAllBoxes();   // place parameter values from file into GUI
					panel1->Refresh();
				}
			}
		}

	}
	private: System::Void resetAllBoxes() {
		// resets all textboxes and labels to match current data in theGear object
		if (theGear != NULL) {
			partIDtextBox->Text = gcnew String(theGear->getPartID().c_str());
			pitchTextBox->Text = Convert::ToString(theGear->getPitch());
			numbTeethTextBox->Text = Convert::ToString(theGear->getNumbTeeth());
			planeTextBox->Text = Convert::ToString(theGear->getPlane());
			startXtextBox->Text = Convert::ToString(theGear->getStartX());
			startYtextBox->Text = Convert::ToString(theGear->getStartY());
			startAngleTextBox->Text = Convert::ToString(theGear->getStartAngle());
			pitchDiamLabel->Text = Convert::ToString(theGear->getPitchDiam());
			colorLabel->BackColor = theGear->getColor();
			if (theGear->getAxle() != NULL) {
				std::string axleID = theGear->getAxle()->partID;
				std::string other = axleID.substr(4);
				int axleIndex = stoi(other) - 1;
				axleComboBox->SelectedItem = axleIndex;
				//axleComboBox->SelectedItem = 2;
				axleComboBox->Refresh();
			}
		}
	}
	private: System::Void saveFileButton_Click(System::Object^  sender, System::EventArgs^  e) {
		IO::Stream^ myStream;
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

		saveFileDialog1->InitialDirectory = ".";  // current folder
		saveFileDialog1->Filter = "gear files (*.gear)|*.gear|All files (*.*)|*.*";
		saveFileDialog1->FilterIndex = 1;  // will show only gear files, but user can choose to show all files
		saveFileDialog1->RestoreDirectory = true;

		if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			using namespace std;

			if ((myStream = saveFileDialog1->OpenFile()) != nullptr)
			{
				labelFeedback->Text = "Saving file: " + saveFileDialog1->FileName;
				//System::Windows::Forms::MessageBox::Show(this, "Just a small pause", "PAUSE");

				myStream->Close();
				delete myStream;

				ofstream outFile;

				// need to convert String^ that comes from file dialog to regular string
				msclr::interop::marshal_context context;
				std::string standardString = context.marshal_as<std::string>(saveFileDialog1->FileName);
				outFile.open(standardString);

				if (outFile.is_open()) {
					theGear->writeFile(outFile);
					outFile.close();
				}
			}
		}

	}
	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
		showTheGrid = checkBox1->Checked;
		panel1->Refresh();
	}

	private: void panel1_MouseWheel(Object^ sender, System::Windows::Forms::MouseEventArgs^ e)
	{
		// panel does not take a mousewheel event, so we must handle it at the the level of the form
		// but only if the mouse pointer is inside the panel
		if (mouseInPanel) {
			float zoomStep = 1.2f;
			int adjustedX = e->X - panel1->Location.X - panel1->Margin.Left;
			int adjustedY = e->Y - panel1->Location.Y - panel1->Margin.Top;
			float oldZoom = zoomLevel;

			//e->Delta * SystemInformation::MouseWheelScrollLines / 120
			if (e->Delta < 0) // zoom out
				zoomLevel = zoomLevel / zoomStep;
			else
				zoomLevel = zoomLevel * zoomStep;

			// reset panX and panY such that the coords under the 
			// mouse pointer are unchanged
			panX = (int)round((adjustedX * (oldZoom - zoomLevel)
				+ panX * zoomLevel) / oldZoom);
			panY = (int)round((adjustedY * (oldZoom - zoomLevel)
				+ panY * zoomLevel) / oldZoom);

			panel1->Refresh();

		}
	}

	private: System::Void rotateScrollBar_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) {
		drawAngle = 360 - rotateScrollBar->Value;
		panel1->Refresh();
	}
	private: System::Void GearEditor_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) {
		readPartID();
		readPitch();
		readNumbTeeth();
		readPlane();
		readStartX();
		readStartY();
		readStartAngle();
	}
	private: System::Void colorLabel_Click(System::Object^  sender, System::EventArgs^  e) {
		ColorDialog^ color01 = gcnew ColorDialog;
		if (color01->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			Color chosenColor = color01->Color;
			colorLabel->BackColor = chosenColor;
			if (theGear != NULL)
				theGear->setColor(chosenColor);
			panel1->Refresh();
			labelFeedback->Text = "Just changed color to A=" + chosenColor.A + ", R="
				+ chosenColor.R + ", G=" + chosenColor.G + ", B=" + chosenColor.B;
		}
	}
	public: int getAxleAssignment() {
		int temp = axleComboBox->SelectedIndex;
		return temp;
	}
	};
}
