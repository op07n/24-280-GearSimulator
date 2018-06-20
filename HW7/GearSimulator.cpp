#include "GearSimulator.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(cli::array <String^> ^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	GearSimulator::GearSimulator form;
	Application::Run(%form);
	return 0;
}
