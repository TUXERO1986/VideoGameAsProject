#include "FrmMainInterface.h"
using namespace ProyectoFinal;
using namespace System;
using namespace System::Drawing;
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(true);
	Application::Run(gcnew FrmMainInterface());
}
