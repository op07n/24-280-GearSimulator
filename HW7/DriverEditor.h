#pragma once
#include "Driver.h"
#include <exception>
#include <iostream>
#include <fstream>
#include <msclr\marshal_cppstd.h>  //  needed for string conversions

namespace DriverEditor {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Windows::Forms::DataVisualization::Charting;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for DriverEditor
	/// </summary>
	public ref class DriverEditor : public System::Windows::Forms::Form
	{
	public:
		DriverEditor(Driver* aDriver) : DriverEditor()
		{
			if (theDriver != NULL)
				delete theDriver;

			theDriver = aDriver;

			reloadCharts();

			this->Refresh();
		}

		DriverEditor(void)
		{
			if (theDriver == NULL)
				theDriver = new Driver;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~DriverEditor()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  readButton;
	protected:
	private: System::Windows::Forms::Button^  writeButton;
	private: System::Windows::Forms::Label^  labelFeedback;


	protected:
		Driver * theDriver;
	private: System::Windows::Forms::TextBox^  inputTextBox;
	protected:

	protected:
	private: System::Windows::Forms::Label^  label1;

	private: System::Windows::Forms::DataVisualization::Charting::Series^  seriesA;
	private: System::Windows::Forms::Button^  getPositionButton;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  XpositionChart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  YpositionChart;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  thetaChart;
	private: System::Windows::Forms::Button^  removeTransX;
	private: System::Windows::Forms::Button^  removeTransY;
	private: System::Windows::Forms::Button^  removeTheta;



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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->readButton = (gcnew System::Windows::Forms::Button());
			this->writeButton = (gcnew System::Windows::Forms::Button());
			this->labelFeedback = (gcnew System::Windows::Forms::Label());
			this->inputTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->getPositionButton = (gcnew System::Windows::Forms::Button());
			this->XpositionChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->YpositionChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->thetaChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->removeTransX = (gcnew System::Windows::Forms::Button());
			this->removeTransY = (gcnew System::Windows::Forms::Button());
			this->removeTheta = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XpositionChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->YpositionChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->thetaChart))->BeginInit();
			this->SuspendLayout();
			// 
			// readButton
			// 
			this->readButton->Location = System::Drawing::Point(10, 12);
			this->readButton->Name = L"readButton";
			this->readButton->Size = System::Drawing::Size(135, 32);
			this->readButton->TabIndex = 0;
			this->readButton->Text = L"Read";
			this->readButton->UseVisualStyleBackColor = true;
			this->readButton->Click += gcnew System::EventHandler(this, &DriverEditor::readButton_Click);
			// 
			// writeButton
			// 
			this->writeButton->Location = System::Drawing::Point(151, 12);
			this->writeButton->Name = L"writeButton";
			this->writeButton->Size = System::Drawing::Size(135, 32);
			this->writeButton->TabIndex = 1;
			this->writeButton->Text = L"Write";
			this->writeButton->UseVisualStyleBackColor = true;
			this->writeButton->Click += gcnew System::EventHandler(this, &DriverEditor::writeButton_Click);
			// 
			// labelFeedback
			// 
			this->labelFeedback->AutoSize = true;
			this->labelFeedback->Location = System::Drawing::Point(13, 97);
			this->labelFeedback->Name = L"labelFeedback";
			this->labelFeedback->Size = System::Drawing::Size(132, 13);
			this->labelFeedback->TabIndex = 2;
			this->labelFeedback->Text = L"Use this area for feedback";
			// 
			// inputTextBox
			// 
			this->inputTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->inputTextBox->Location = System::Drawing::Point(49, 50);
			this->inputTextBox->Name = L"inputTextBox";
			this->inputTextBox->Size = System::Drawing::Size(375, 20);
			this->inputTextBox->TabIndex = 3;
			this->inputTextBox->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &DriverEditor::inputTextBox_KeyDown);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(31, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Input";
			// 
			// getPositionButton
			// 
			this->getPositionButton->Location = System::Drawing::Point(292, 12);
			this->getPositionButton->Name = L"getPositionButton";
			this->getPositionButton->Size = System::Drawing::Size(135, 32);
			this->getPositionButton->TabIndex = 6;
			this->getPositionButton->Text = L"Position";
			this->getPositionButton->UseVisualStyleBackColor = true;
			this->getPositionButton->Click += gcnew System::EventHandler(this, &DriverEditor::getPositionButton_Click);
			// 
			// XpositionChart
			// 
			chartArea1->AxisX->Title = L"Time (ms)";
			chartArea1->AxisY->Title = L"Position X";
			chartArea1->Name = L"ChartArea1";
			this->XpositionChart->ChartAreas->Add(chartArea1);
			this->XpositionChart->Location = System::Drawing::Point(10, 131);
			this->XpositionChart->Name = L"XpositionChart";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Color = System::Drawing::Color::Red;
			series1->Name = L"Series1";
			this->XpositionChart->Series->Add(series1);
			this->XpositionChart->Size = System::Drawing::Size(413, 133);
			this->XpositionChart->TabIndex = 7;
			this->XpositionChart->Text = L"XpositionChart";
			// 
			// YpositionChart
			// 
			chartArea2->AxisX->Title = L"Time (ms)";
			chartArea2->AxisY->Title = L"Position Y";
			chartArea2->Name = L"ChartArea1";
			this->YpositionChart->ChartAreas->Add(chartArea2);
			this->YpositionChart->Location = System::Drawing::Point(10, 270);
			this->YpositionChart->Name = L"YpositionChart";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->Color = System::Drawing::Color::Red;
			series2->Name = L"Series1";
			this->YpositionChart->Series->Add(series2);
			this->YpositionChart->Size = System::Drawing::Size(413, 132);
			this->YpositionChart->TabIndex = 8;
			this->YpositionChart->Text = L"chart1";
			// 
			// thetaChart
			// 
			chartArea3->AxisX->Title = L"Time (ms)";
			chartArea3->AxisY->Title = L"Rotation (rads)";
			chartArea3->Name = L"ChartArea1";
			this->thetaChart->ChartAreas->Add(chartArea3);
			this->thetaChart->Location = System::Drawing::Point(10, 408);
			this->thetaChart->Name = L"thetaChart";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->Color = System::Drawing::Color::Red;
			series3->Name = L"Series1";
			this->thetaChart->Series->Add(series3);
			this->thetaChart->Size = System::Drawing::Size(413, 147);
			this->thetaChart->TabIndex = 9;
			this->thetaChart->Text = L"chart1";
			// 
			// removeTransX
			// 
			this->removeTransX->Location = System::Drawing::Point(357, 243);
			this->removeTransX->Name = L"removeTransX";
			this->removeTransX->Size = System::Drawing::Size(70, 21);
			this->removeTransX->TabIndex = 10;
			this->removeTransX->Text = L"Remove";
			this->removeTransX->UseVisualStyleBackColor = true;
			this->removeTransX->Click += gcnew System::EventHandler(this, &DriverEditor::removeTransX_Click);
			// 
			// removeTransY
			// 
			this->removeTransY->Location = System::Drawing::Point(353, 381);
			this->removeTransY->Name = L"removeTransY";
			this->removeTransY->Size = System::Drawing::Size(70, 21);
			this->removeTransY->TabIndex = 11;
			this->removeTransY->Text = L"Remove";
			this->removeTransY->UseVisualStyleBackColor = true;
			this->removeTransY->Click += gcnew System::EventHandler(this, &DriverEditor::removeTransY_Click);
			// 
			// removeTheta
			// 
			this->removeTheta->Location = System::Drawing::Point(354, 534);
			this->removeTheta->Name = L"removeTheta";
			this->removeTheta->Size = System::Drawing::Size(70, 21);
			this->removeTheta->TabIndex = 12;
			this->removeTheta->Text = L"Remove";
			this->removeTheta->UseVisualStyleBackColor = true;
			this->removeTheta->Click += gcnew System::EventHandler(this, &DriverEditor::removeTheta_Click);
			// 
			// DriverEditor
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(436, 567);
			this->Controls->Add(this->removeTheta);
			this->Controls->Add(this->removeTransY);
			this->Controls->Add(this->removeTransX);
			this->Controls->Add(this->thetaChart);
			this->Controls->Add(this->YpositionChart);
			this->Controls->Add(this->XpositionChart);
			this->Controls->Add(this->getPositionButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->inputTextBox);
			this->Controls->Add(this->labelFeedback);
			this->Controls->Add(this->writeButton);
			this->Controls->Add(this->readButton);
			this->Name = L"DriverEditor";
			this->Text = L"DriverEditor";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->XpositionChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->YpositionChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->thetaChart))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void readButton_Click(System::Object^  sender, System::EventArgs^  e) {

		IO::Stream^ myStream;
		OpenFileDialog^ openFileDialog1 = gcnew OpenFileDialog;

		openFileDialog1->InitialDirectory = ".";  // current folder
		openFileDialog1->Filter = "motion files (*.mot)|*.mot|All files (*.*)|*.*";
		openFileDialog1->FilterIndex = 1;  // will show only gear files, but user can choose to show all files
		openFileDialog1->RestoreDirectory = true;

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			using namespace std;

			if ((myStream = openFileDialog1->OpenFile()) != nullptr)
			{
				labelFeedback->Text = "Opening file: " + openFileDialog1->FileName;
				//System::Windows::Forms::MessageBox::Show(this, "Just a small pause", "PAUSE");

				ifstream inFile;

				// need to convert String^ that comes from file dialog to regular string
				msclr::interop::marshal_context context;
				std::string standardString = context.marshal_as<std::string>(openFileDialog1->FileName);
				inFile.open(standardString);
				if (inFile.is_open()) {
					//delete theDriver;
					theDriver->readFile(inFile);
					inFile.close();
					reloadCharts();

					this->Refresh();

				}
			}
		}

	}

	private: System::Void writeButton_Click(System::Object^  sender, System::EventArgs^  e) {
		IO::Stream^ myStream;
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;

		saveFileDialog1->InitialDirectory = ".";  // current folder
		saveFileDialog1->Filter = "motion files (*.mot)|*.mot|All files (*.*)|*.*";
		saveFileDialog1->FilterIndex = 1;  // will show only motion files, but user can choose to show all files
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
					MotionDirection mDir = MotionDirection::THETA;
					MotionType mType = MotionType::POSITION;
					if (inputTextBox->Text->Contains("X"))
						mDir = MotionDirection::X;
					else if (inputTextBox->Text->Contains("Y"))
						mDir = MotionDirection::Y;
					else if (inputTextBox->Text->Contains("THETA"))
						mDir = MotionDirection::THETA;

					if (inputTextBox->Text->Contains("POS"))
						mType = MotionType::POSITION;
					else if (inputTextBox->Text->Contains("VEL"))
						mType = MotionType::VELOCITY;
					else if (inputTextBox->Text->Contains("ACC"))
						mType = MotionType::ACCELERATION;

					theDriver->writeFile(outFile, mDir, mType);
					outFile.close();
				}
			}
		}

	}

	private: System::Void inputTextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e) {
		if (e->KeyCode == Keys::Enter) {
			labelFeedback->Text = "Someone pressed 'Enter' in textBox.";
		}
	}

	private: System::Void getPositionButton_Click(System::Object^  sender, System::EventArgs^  e) {
		MotionDirection mDir = MotionDirection::THETA;
		if (inputTextBox->Text->Contains("X"))
			mDir = MotionDirection::X;
		else if (inputTextBox->Text->Contains("Y"))
			mDir = MotionDirection::Y;
		else if (inputTextBox->Text->Contains("THETA"))
			mDir = MotionDirection::THETA;

		try {
			double wanted = Convert::ToDouble(inputTextBox->Text->Substring(0, 4));
			double theValue = theDriver->getPosition(wanted, mDir);

			labelFeedback->Text = "The value at " + Convert::ToString(wanted) + " is " + Convert::ToString(theValue);
		}
		catch (Exception^ excep) {
			labelFeedback->Text = "Could not get position";
		}
	}
	private: System::Void reloadCharts() {

		theDriver->loadChart(this->XpositionChart->Series->FindByName("Series1"), MotionDirection::X);
		theDriver->loadChart(this->YpositionChart->Series->FindByName("Series1"), MotionDirection::Y);
		theDriver->loadChart(this->thetaChart->Series->FindByName("Series1"), MotionDirection::THETA);

	}

	private: System::Void removeTransX_Click(System::Object^  sender, System::EventArgs^  e) {
		theDriver->removeMotion(MotionDirection::X);
		labelFeedback->Text = "TransX motion removed";
		reloadCharts();
	}
	private: System::Void removeTransY_Click(System::Object^  sender, System::EventArgs^  e) {
		theDriver->removeMotion(MotionDirection::Y);
		labelFeedback->Text = "TransY motion removed";
		reloadCharts();
	}
	private: System::Void removeTheta_Click(System::Object^  sender, System::EventArgs^  e) {
		theDriver->removeMotion(MotionDirection::THETA);
		labelFeedback->Text = "Theta motion removed";
		reloadCharts();
	}
	};
}
