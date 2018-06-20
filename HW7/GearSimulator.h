#pragma once
//#include <cliext/vector>
#include "GearEditor.h"
#include "AxleEditor.h"
#include "DriverEditor.h"
#include <exception>
#include <iostream>
#include <fstream>
#include <msclr\marshal_cppstd.h>  //  needed for string conversions


// using flickerless panel makes the form design view not work.
// to use flickerless panel or allow the design view, use one of these
// in InitComponents() function
//    for design view >>>>    this->panel1 = (gcnew System::Windows::Forms::Panel());
//    for flickerless >>>>    this->panel1 = (gcnew FlickerLessPanel());


 #include "FlickerLessPanel.h"

namespace GearSimulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//using namespace System::Collections::Generic;
	using namespace System::Collections;

	/// <summary>
	/// Summary for GearSimulator
	/// </summary>
	public ref class GearSimulator : public System::Windows::Forms::Form
	{
	public:
		GearSimulator(void)
		{
			//theGear = new Gear2D;
			mouseInPanel = false;
			panX = 300;
			panY = 300;
			zoomLevel = 60.0f;
			showTheGrid = false;
			drawAngle = 0;
			lastNumbPetals = 0;
			lastDiameter = 0.0;
			steps = 0;
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
		~GearSimulator()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  labelFeedback;
	protected:

	private: System::Windows::Forms::Panel^  panel1;











	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
		int lastNumbPetals;
		float lastDiameter;
		bool mouseInPanel;
		int panX;
		int panY;
		int currX, currY;
		float zoomLevel;
		Gear2D *theGear = NULL;
		std::vector<Axle *>* theAxles = NULL;
		std::vector<Gear2D *>* theGears = NULL;
		Axle *theAxle = NULL;
		Driver *theDriver = NULL;
		bool showTheGrid;
		int drawAngle;
		int steps;
	private: System::Windows::Forms::Button^  addGearButton;


	private: System::Windows::Forms::Button^  addDriverButton;

	private: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;

	private: System::Windows::Forms::HScrollBar^  rotateScrollBar;
	private: System::Windows::Forms::Button^  addAxleButton;
	private: System::Windows::Forms::Button^  resetSimButton;

	private: System::Windows::Forms::Button^  runSimButton;
	private: System::Windows::Forms::Button^  editAxleButton;
	private: System::Windows::Forms::ComboBox^  axleListCombo;
	private: System::Windows::Forms::ComboBox^  gearListCombo;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  driverCombo;
	private: System::Windows::Forms::Button^  stepSimButton;
	private: System::Windows::Forms::Button^  cyclicsim;


	private: System::Windows::Forms::Button^  editGearButton;


#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Required method for Designer support - do not modify
			 /// the contents of this method with the code editor.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->labelFeedback = (gcnew System::Windows::Forms::Label());
				 this->panel1 = (gcnew FlickerLessPanel());
				 this->addGearButton = (gcnew System::Windows::Forms::Button());
				 this->addDriverButton = (gcnew System::Windows::Forms::Button());
				 this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
				 this->label9 = (gcnew System::Windows::Forms::Label());
				 this->label10 = (gcnew System::Windows::Forms::Label());
				 this->rotateScrollBar = (gcnew System::Windows::Forms::HScrollBar());
				 this->addAxleButton = (gcnew System::Windows::Forms::Button());
				 this->resetSimButton = (gcnew System::Windows::Forms::Button());
				 this->runSimButton = (gcnew System::Windows::Forms::Button());
				 this->editAxleButton = (gcnew System::Windows::Forms::Button());
				 this->axleListCombo = (gcnew System::Windows::Forms::ComboBox());
				 this->gearListCombo = (gcnew System::Windows::Forms::ComboBox());
				 this->editGearButton = (gcnew System::Windows::Forms::Button());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->driverCombo = (gcnew System::Windows::Forms::ComboBox());
				 this->stepSimButton = (gcnew System::Windows::Forms::Button());
				 this->cyclicsim = (gcnew System::Windows::Forms::Button());
				 this->SuspendLayout();
				 // 
				 // labelFeedback
				 // 
				 this->labelFeedback->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
				 this->labelFeedback->AutoSize = true;
				 this->labelFeedback->Location = System::Drawing::Point(24, 928);
				 this->labelFeedback->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
				 this->labelFeedback->Name = L"labelFeedback";
				 this->labelFeedback->Size = System::Drawing::Size(118, 25);
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
				 this->panel1->Location = System::Drawing::Point(196, 79);
				 this->panel1->Margin = System::Windows::Forms::Padding(6);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(1319, 824);
				 this->panel1->TabIndex = 1;
				 this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &GearSimulator::panel1_Paint);
				 this->panel1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &GearSimulator::panel1_MouseClick);
				 this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &GearSimulator::panel1_MouseDown);
				 this->panel1->MouseEnter += gcnew System::EventHandler(this, &GearSimulator::panel1_MouseEnter);
				 this->panel1->MouseLeave += gcnew System::EventHandler(this, &GearSimulator::panel1_MouseLeave);
				 this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &GearSimulator::panel1_MouseMove);
				 // 
				 // addGearButton
				 // 
				 this->addGearButton->Location = System::Drawing::Point(8, 390);
				 this->addGearButton->Margin = System::Windows::Forms::Padding(6);
				 this->addGearButton->Name = L"addGearButton";
				 this->addGearButton->Size = System::Drawing::Size(168, 44);
				 this->addGearButton->TabIndex = 17;
				 this->addGearButton->Text = L"Add Gear";
				 this->addGearButton->UseVisualStyleBackColor = true;
				 this->addGearButton->Click += gcnew System::EventHandler(this, &GearSimulator::addGearButton_Click);
				 this->addGearButton->MouseLeave += gcnew System::EventHandler(this, &GearSimulator::textBox1_MouseLeave);
				 this->addGearButton->MouseHover += gcnew System::EventHandler(this, &GearSimulator::editGearButton_MouseHover);
				 // 
				 // addDriverButton
				 // 
				 this->addDriverButton->Location = System::Drawing::Point(8, 575);
				 this->addDriverButton->Margin = System::Windows::Forms::Padding(6);
				 this->addDriverButton->Name = L"addDriverButton";
				 this->addDriverButton->Size = System::Drawing::Size(168, 44);
				 this->addDriverButton->TabIndex = 18;
				 this->addDriverButton->Text = L"Add Driver";
				 this->addDriverButton->UseVisualStyleBackColor = true;
				 this->addDriverButton->Click += gcnew System::EventHandler(this, &GearSimulator::addDriverButton_Click);
				 this->addDriverButton->MouseLeave += gcnew System::EventHandler(this, &GearSimulator::textBox1_MouseLeave);
				 this->addDriverButton->MouseHover += gcnew System::EventHandler(this, &GearSimulator::saveFileButton_MouseHover);
				 // 
				 // checkBox1
				 // 
				 this->checkBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
				 this->checkBox1->Appearance = System::Windows::Forms::Appearance::Button;
				 this->checkBox1->AutoSize = true;
				 this->checkBox1->Location = System::Drawing::Point(1404, 927);
				 this->checkBox1->Margin = System::Windows::Forms::Padding(6);
				 this->checkBox1->Name = L"checkBox1";
				 this->checkBox1->Size = System::Drawing::Size(115, 35);
				 this->checkBox1->TabIndex = 19;
				 this->checkBox1->Text = L"ShowGrid";
				 this->checkBox1->UseVisualStyleBackColor = true;
				 this->checkBox1->CheckedChanged += gcnew System::EventHandler(this, &GearSimulator::checkBox1_CheckedChanged);
				 // 
				 // label9
				 // 
				 this->label9->AutoSize = true;
				 this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label9->Location = System::Drawing::Point(4, 17);
				 this->label9->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
				 this->label9->Name = L"label9";
				 this->label9->Size = System::Drawing::Size(302, 48);
				 this->label9->TabIndex = 20;
				 this->label9->Text = L"Gear Simulator";
				 // 
				 // label10
				 // 
				 this->label10->AutoSize = true;
				 this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(0)));
				 this->label10->Location = System::Drawing::Point(1170, 40);
				 this->label10->Margin = System::Windows::Forms::Padding(6, 0, 6, 0);
				 this->label10->Name = L"label10";
				 this->label10->Size = System::Drawing::Size(87, 30);
				 this->label10->TabIndex = 21;
				 this->label10->Text = L"(ng27)";
				 // 
				 // rotateScrollBar
				 // 
				 this->rotateScrollBar->Location = System::Drawing::Point(444, 42);
				 this->rotateScrollBar->Maximum = 360;
				 this->rotateScrollBar->Name = L"rotateScrollBar";
				 this->rotateScrollBar->Size = System::Drawing::Size(698, 13);
				 this->rotateScrollBar->TabIndex = 24;
				 this->rotateScrollBar->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &GearSimulator::rotateScrollBar_Scroll);
				 // 
				 // addAxleButton
				 // 
				 this->addAxleButton->Location = System::Drawing::Point(10, 212);
				 this->addAxleButton->Margin = System::Windows::Forms::Padding(6);
				 this->addAxleButton->Name = L"addAxleButton";
				 this->addAxleButton->Size = System::Drawing::Size(168, 44);
				 this->addAxleButton->TabIndex = 25;
				 this->addAxleButton->Text = L"Add Axle";
				 this->addAxleButton->UseVisualStyleBackColor = true;
				 this->addAxleButton->Click += gcnew System::EventHandler(this, &GearSimulator::addAxleButton_Click);
				 // 
				 // resetSimButton
				 // 
				 this->resetSimButton->Location = System::Drawing::Point(8, 686);
				 this->resetSimButton->Margin = System::Windows::Forms::Padding(6);
				 this->resetSimButton->Name = L"resetSimButton";
				 this->resetSimButton->Size = System::Drawing::Size(168, 44);
				 this->resetSimButton->TabIndex = 26;
				 this->resetSimButton->Text = L"Reset Sim";
				 this->resetSimButton->UseVisualStyleBackColor = true;
				 this->resetSimButton->Click += gcnew System::EventHandler(this, &GearSimulator::resetSimButton_Click);
				 // 
				 // runSimButton
				 // 
				 this->runSimButton->Location = System::Drawing::Point(10, 742);
				 this->runSimButton->Margin = System::Windows::Forms::Padding(6);
				 this->runSimButton->Name = L"runSimButton";
				 this->runSimButton->Size = System::Drawing::Size(168, 44);
				 this->runSimButton->TabIndex = 28;
				 this->runSimButton->Text = L"Run Sim";
				 this->runSimButton->UseVisualStyleBackColor = true;
				 this->runSimButton->Click += gcnew System::EventHandler(this, &GearSimulator::runSimButton_Click);
				 // 
				 // editAxleButton
				 // 
				 this->editAxleButton->Location = System::Drawing::Point(10, 267);
				 this->editAxleButton->Margin = System::Windows::Forms::Padding(6);
				 this->editAxleButton->Name = L"editAxleButton";
				 this->editAxleButton->Size = System::Drawing::Size(168, 44);
				 this->editAxleButton->TabIndex = 29;
				 this->editAxleButton->Text = L"Edit Axle";
				 this->editAxleButton->UseVisualStyleBackColor = true;
				 this->editAxleButton->Click += gcnew System::EventHandler(this, &GearSimulator::editAxleButton_Click);
				 // 
				 // axleListCombo
				 // 
				 this->axleListCombo->FormattingEnabled = true;
				 this->axleListCombo->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
					 L"Axle1", L"Axle2", L"Axle3", L"Axle4", L"Axle5",
						 L"Axle6", L"Axle7", L"Axle8", L"Axle9"
				 });
				 this->axleListCombo->Location = System::Drawing::Point(10, 313);
				 this->axleListCombo->Margin = System::Windows::Forms::Padding(6);
				 this->axleListCombo->Name = L"axleListCombo";
				 this->axleListCombo->Size = System::Drawing::Size(162, 33);
				 this->axleListCombo->TabIndex = 30;
				 // 
				 // gearListCombo
				 // 
				 this->gearListCombo->FormattingEnabled = true;
				 this->gearListCombo->Location = System::Drawing::Point(10, 492);
				 this->gearListCombo->Margin = System::Windows::Forms::Padding(6);
				 this->gearListCombo->Name = L"gearListCombo";
				 this->gearListCombo->Size = System::Drawing::Size(162, 33);
				 this->gearListCombo->TabIndex = 32;
				 // 
				 // editGearButton
				 // 
				 this->editGearButton->Location = System::Drawing::Point(10, 446);
				 this->editGearButton->Margin = System::Windows::Forms::Padding(6);
				 this->editGearButton->Name = L"editGearButton";
				 this->editGearButton->Size = System::Drawing::Size(168, 44);
				 this->editGearButton->TabIndex = 31;
				 this->editGearButton->Text = L"Edit Gear";
				 this->editGearButton->UseVisualStyleBackColor = true;
				 this->editGearButton->Click += gcnew System::EventHandler(this, &GearSimulator::editGearButton_Click);
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(8, 133);
				 this->button1->Margin = System::Windows::Forms::Padding(6);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(168, 44);
				 this->button1->TabIndex = 33;
				 this->button1->Text = L"Save Sim";
				 this->button1->UseVisualStyleBackColor = true;
				 // 
				 // button2
				 // 
				 this->button2->Location = System::Drawing::Point(8, 79);
				 this->button2->Margin = System::Windows::Forms::Padding(6);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(168, 44);
				 this->button2->TabIndex = 34;
				 this->button2->Text = L"Load Sim";
				 this->button2->UseVisualStyleBackColor = true;
				 // 
				 // driverCombo
				 // 
				 this->driverCombo->FormattingEnabled = true;
				 this->driverCombo->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
					 L"Axle1", L"Axle2", L"Axle3", L"Axle4", L"Axle5",
						 L"Axle6", L"Axle7", L"Axle8", L"Axle9"
				 });
				 this->driverCombo->Location = System::Drawing::Point(10, 627);
				 this->driverCombo->Margin = System::Windows::Forms::Padding(6);
				 this->driverCombo->Name = L"driverCombo";
				 this->driverCombo->Size = System::Drawing::Size(162, 33);
				 this->driverCombo->TabIndex = 35;
				 this->driverCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &GearSimulator::driverCombo_SelectedIndexChanged);
				 // 
				 // stepSimButton
				 // 
				 this->stepSimButton->Location = System::Drawing::Point(12, 795);
				 this->stepSimButton->Name = L"stepSimButton";
				 this->stepSimButton->Size = System::Drawing::Size(166, 40);
				 this->stepSimButton->TabIndex = 36;
				 this->stepSimButton->Text = L"Step Sim";
				 this->stepSimButton->UseVisualStyleBackColor = true;
				 this->stepSimButton->Click += gcnew System::EventHandler(this, &GearSimulator::stepSimButton_Click);
				 // 
				 // cyclicsim
				 // 
				 this->cyclicsim->Location = System::Drawing::Point(10, 841);
				 this->cyclicsim->Name = L"cyclicsim";
				 this->cyclicsim->Size = System::Drawing::Size(166, 40);
				 this->cyclicsim->TabIndex = 37;
				 this->cyclicsim->Text = L"Cyclic Sim";
				 this->cyclicsim->UseVisualStyleBackColor = true;
				 this->cyclicsim->Click += gcnew System::EventHandler(this, &GearSimulator::cyclicbutton_Click);
				 // 
				 // GearSimulator
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(12, 25);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(1543, 974);
				 this->Controls->Add(this->cyclicsim);
				 this->Controls->Add(this->stepSimButton);
				 this->Controls->Add(this->driverCombo);
				 this->Controls->Add(this->button2);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->gearListCombo);
				 this->Controls->Add(this->editGearButton);
				 this->Controls->Add(this->axleListCombo);
				 this->Controls->Add(this->editAxleButton);
				 this->Controls->Add(this->runSimButton);
				 this->Controls->Add(this->resetSimButton);
				 this->Controls->Add(this->addAxleButton);
				 this->Controls->Add(this->rotateScrollBar);
				 this->Controls->Add(this->label10);
				 this->Controls->Add(this->label9);
				 this->Controls->Add(this->checkBox1);
				 this->Controls->Add(this->addDriverButton);
				 this->Controls->Add(this->addGearButton);
				 this->Controls->Add(this->panel1);
				 this->Controls->Add(this->labelFeedback);
				 this->Margin = System::Windows::Forms::Padding(6);
				 this->Name = L"GearSimulator";
				 this->Text = L"GearSimulator";
				 this->Load += gcnew System::EventHandler(this, &GearSimulator::GearSimulator_Load);
				 this->MouseWheel += gcnew System::Windows::Forms::MouseEventHandler(this, &GearSimulator::panel1_MouseWheel);
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion
	private: System::Void panel1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
		Graphics^ g = e->Graphics;
		Pen^ blackPen = gcnew Pen(Color::Black, 3.0f);
		Pen^ redPen = gcnew Pen(Color::Red, 3.0f);
		Pen^ bluePen = gcnew Pen(Color::Blue, 3.0f);
		float adj = 1000.;

		g->TranslateTransform((float)panX, (float)panY);

		g->ScaleTransform(zoomLevel / adj, -zoomLevel / adj);

		// show grid draws a space of 0.5-inch spacing, 50 inches around system center
		if (showTheGrid)
			showGrid(g, 0.5f*adj, 50.f*adj, 50.f*adj);

		//g->RotateTransform(drawAngle);
		labelFeedback->Text = "";

		if (theGears != NULL) {
			Pen^ gearPen;
			for (int i = 0; i < theGears->size(); i++) {
				if ((*theGears)[i]->canCalculate()) {
					gearPen = gcnew Pen((*theGears)[i]->getColor(), 3.0f);
					(*theGears)[i]->paint(g, gearPen, adj);
				}
			}
		}
		else
			labelFeedback->Text = "No gears loaded";

		if (theAxles != NULL) {
			for (int i = 0; i < theAxles->size(); i++) {
				(*theAxles)[i]->paint(g, bluePen, adj);
			}
		}
		else
			labelFeedback->Text += "  No axles loaded";
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
	private: System::Void editGearButton_MouseHover(System::Object^  sender, System::EventArgs^  e) {
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
	private: System::Void addGearButton_Click(System::Object^  sender, System::EventArgs^  e) {
		// as a dialog
		//if (theGear == NULL)
		//	theGear = new Gear2D;
		//GearEditor::GearEditor gearForm(theGear);
		//gearForm.ShowDialog();
		//theGear->reset();

		if (theGears == NULL)
			theGears = new std::vector<Gear2D *>;

		Gear2D *newGear = new Gear2D;
		GearEditor::GearEditor gearForm(newGear);
		gearForm.ShowDialog();
		if (newGear->canCalculate()) {
			int axleIndex = gearForm.getAxleAssignment();
			if (theAxles != NULL && theAxles->size() > axleIndex) {
				Axle *wantedAxle = (*theAxles)[axleIndex];
				wantedAxle->addGear(newGear, 0,0);
				//wantedAxle->addGear(newGear, newGear->currX, newGear->currY);
			}
			else
				labelFeedback->Text = "Not able to assign new gear to an axle.";

			newGear->reset();

			for (int i = 0; i < theGears->size(); i++) {
				if (newGear->canMesh(theGears->at(i))) {
					newGear->addMeshedGear(theGears->at(i));
					

				}
			}

			
			theGears->push_back(newGear);
			loadGearCombo();
		}
		else {
			delete newGear;
			labelFeedback->Text = "Not able to add new gear to simulation because it was insufficiently defined.";
		}
		panel1->Refresh();

		// as a normal form
		//GearEditor::GearEditor^ gearForm = gcnew GearEditor::GearEditor;
		//gearForm->Show();

	}
	private: System::Void addAxleButton_Click(System::Object^  sender, System::EventArgs^  e) {

		//if (theAxle == NULL)
		//	theAxle = new Axle;
		if (theAxles == NULL)
			theAxles = new std::vector<Axle *>; ;

		Axle *newAxle = new Axle;
		String ^newPartID = "Axle" + (theAxles->size() + 1);

		msclr::interop::marshal_context context;
		std::string partID = context.marshal_as<std::string>(newPartID);

		newAxle->partID = partID;

		AxleEditor axleForm(newAxle);
		axleForm.ShowDialog();
		newAxle->reset();
		theAxles->push_back(newAxle);
		panel1->Refresh();
	}

	private: System::Void resetAllBoxes() {
		// resets all textboxes and labels to match current data in theGear object
		//		partIDtextBox->Text = gcnew String(theGear->getPartID().c_str());
		//		pitchTextBox->Text = Convert::ToString(theGear->getPitch());
		//		numbTeethTextBox->Text = Convert::ToString(theGear->getNumbTeeth());
		//		planeTextBox->Text = Convert::ToString(theGear->getPlane());
		//		startXtextBox->Text = Convert::ToString(theGear->getStartX());
		//		startYtextBox->Text = Convert::ToString(theGear->getStartY());
		//		startAngleTextBox->Text = Convert::ToString(theGear->getStartAngle());
		//		pitchDiamLabel->Text = Convert::ToString(theGear->getPitchDiam());

	}
	private: System::Void addDriverButton_Click(System::Object^  sender, System::EventArgs^  e) {
		// as a dialog
		if (theDriver == NULL)
			theDriver = new Driver;

		DriverEditor::DriverEditor driverForm(theDriver);
		driverForm.ShowDialog();

		//DriverEditor::DriverEditor^ driverForm = gcnew DriverEditor::DriverEditor(theDriver);
		//DriverEditor::DriverEditor^ driverForm = gcnew DriverEditor::DriverEditor();
		//driverForm->Show();
		panel1->Refresh();


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

	private: System::Void resetSimButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (theDriver == NULL || theAxles == NULL || theAxles->empty())
			labelFeedback->Text = "Cannot run simulation.";
		else {
			if (theGears != NULL)
				for (int i = 0; i < theGears->size(); i++)
					theGears->at(i)->reset();
			for (int i = 0; i < theAxles->size(); i++)
				theAxles->at(i)->reset();
			theDriver->reset();

			panel1->Refresh();
		}

	}
	private: System::Void runSimButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (theDriver == NULL || theAxles == NULL || theAxles->empty())
			labelFeedback->Text = "Cannot run simulation.";
		else {
			resetSimButton_Click(sender, e);
			//theAxle->addGear(theGear, 0, 0);
			assignDriver();
			theDriver->startSim(panel1, 20);
		}
	}
	private: System::Void editAxleButton_Click(System::Object^  sender, System::EventArgs^  e) {
		int axleIndex = axleListCombo->SelectedIndex;
		if (theAxles != NULL && theAxles->size() > axleIndex) {

			Axle *editAxle = theAxles->at(axleIndex);

			AxleEditor axleForm(editAxle);
			axleForm.ShowDialog();
			editAxle->reset();
			panel1->Refresh();
		}
		else
			labelFeedback->Text = "Cannot edit axle";
	}
	private: System::Void loadGearCombo() {
		gearListCombo->Items->Clear();
		for (int i = 0; i < theGears->size(); i++) {
			gearListCombo->Items->Add(gcnew String(theGears->at(i)->getPartID().c_str()));

		}

	}
	private: System::Void editGearButton_Click(System::Object^  sender, System::EventArgs^  e) {
		int gearIndex = gearListCombo->SelectedIndex;
		if (theGears != NULL && theGears->size() > gearIndex) {

			Gear2D *editGear = theGears->at(gearIndex);

			GearEditor::GearEditor gearForm(editGear);
			gearForm.ShowDialog();
			int axleIndex = gearForm.getAxleAssignment();
			if (theAxles != NULL && theAxles->size() > axleIndex) {
				Axle *wantedAxle = (*theAxles)[axleIndex];
				wantedAxle->addGear(editGear, 0, 0);
			}
			else
				labelFeedback->Text = "Not able to assign new gear to an axle.";

			editGear->unmeshAll();
			editGear->reset();
			for (int i = 0; i < theGears->size(); i++) {
				if (editGear->canMesh(theGears->at(i))) {
					editGear->addMeshedGear(theGears->at(i));
				}
			}

			panel1->Refresh();
		}
		else
			labelFeedback->Text = "Cannot edit gear";
	}
	private: System::Void driverCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
		// attach driver to chosen gear
		assignDriver();
	}
	private: System::Void assignDriver() {
		int axleIndex = driverCombo->SelectedIndex;
		if (theDriver != NULL && theAxles != NULL && theAxles->size() > axleIndex) {
			Axle *targetAxle = (*theAxles)[axleIndex];
			theDriver->setAxle(targetAxle);
		}
	}
	private: System::Void GearSimulator_Load(System::Object^  sender, System::EventArgs^  e) {
	}

	private: System::Void stepSimButton_Click(System::Object^  sender, System::EventArgs^  e) {
		if (theDriver == NULL || theAxles == NULL || theAxles->empty()) {
			label10->Text = "Cannot run simulation. one";
		}
		else if (steps == 0) {
			steps += 1;
			resetSimButton_Click(sender, e);
			
			assignDriver();

		}
		if (steps > 0) {
			steps += 1;
			theDriver->stepSim(panel1);
		}
	}



private: System::Void cyclicbutton_Click(System::Object^  sender, System::EventArgs^  e) {
	if (theDriver == NULL || theAxles == NULL || theAxles->empty())
		labelFeedback->Text = "Cannot run simulation.";
	else {
		resetSimButton_Click(sender, e);
		//theAxle->addGear(theGear, 0, 0);
		assignDriver();
		for (int i = 0; i < 3; i++) {
			theDriver->startSim(panel1, 20);
			theDriver->reverseSim(panel1, 20);
		}
	}

}
};
}


