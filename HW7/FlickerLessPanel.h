#pragma once
ref class FlickerLessPanel : public System::Windows::Forms::Panel
{

public: FlickerLessPanel()
{
	this->DoubleBuffered = true;
}
};

