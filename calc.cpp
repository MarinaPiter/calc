#define _CRT_SECURE_NO_WARNINGS 
#include <windows.h> 
#include <stdio.h> 
#include <FL/Fl.H> 
#include <FL/Fl_Double_Window.H> 
#include <FL/Fl_Button.H> 
#include <FL/Fl_Input.H> 
#include <FL/Fl_Widget.H> 
#include <iostream>
#include <string>
using namespace std;

double a = 0;
char* buffer = new char;
int x;

void answer(Fl_Input* s)
{
	switch (x)
	{
	case'+': 
	{
	a = a + atof(s->value());
	sprintf(buffer, "%.16g", a);
	s->value(buffer);
	break;
	}
	case'-': 
	{
	a = a - atof(s->value());
	sprintf(buffer, "%.16g", a);
	s->value(buffer);
	break;
	}
	case'*':
	{
	 a = a*atof(s->value());
	 sprintf(buffer, "%.16g", a);
	 s->value(buffer);
	 break;
	}
	case'/':
	{
	a = a / atof(s->value());
	sprintf(buffer, "%.16g", a);
	s->value(buffer);
	break;
	}
	}
}
void button_callback_oper(Fl_Widget* widget, void* d)
{
	Fl_Input* s = (Fl_Input*)d;
	if(a==0)
	{
	a = atof(s->value());
	}
	else
	{
		answer(s);
	}
	switch(widget->label()[0])
	{
	case'+': {x = '+';s->value("");break;}
	case'-': {x = '-';s->value("");break;}
	case'*': {x = '*';s->value("");break;}
	case'/': {x = '/';s->value("");break;}
	default : break;
	}
}
void button_callback_answr(Fl_Widget* widget, void* d)
{
	Fl_Input* s = (Fl_Input*)d;
	answer(s);
	a = 0;
}
void button_callback_back(Fl_Widget* widget, void* d)
{
	Fl_Input* s = (Fl_Input*)d;
	string j = s->value();
	if(strlen(j.c_str()) != 0)
	{
	j.pop_back();
	s->value(j.c_str());
	}
}
void button_callback_number(Fl_Widget* widget, void* d)
{
	Fl_Input* s = (Fl_Input*)d;
	string j = s->value();
	j += widget->label()[0];
	s->value(j.c_str());
}
void button_callback_clear(Fl_Widget* widget, void* d)
{
	Fl_Input* s = (Fl_Input*)d;
	a=0;
	s->value("");
	strcpy(buffer,"");
	x=0;
}
int main(int argc, char * argv[])
{
	Fl_Window* window = new Fl_Window(240, 258, "Calc");
	Fl_Input* in1 = new Fl_Input(0, 0, 240, 30, 0);
	Fl_Button* button_back = new Fl_Button(0, 30, 240, 30, "<-");
	Fl_Button* button_plus = new Fl_Button(200, 60, 40, 39.6, "+");
	Fl_Button* button_minus = new Fl_Button(200, 60 + 39.6, 40, 39.6, "-");
	Fl_Button* button_mult = new Fl_Button(200, 60 + 39.6*2, 40, 39.6, "*");
	Fl_Button* button_div = new Fl_Button(200, 60 + 39.6*3, 40, 39.6, "/");
	Fl_Button* button_answr = new Fl_Button(200, 60 + 39.6*4, 40, 39.6, "=");
	button_plus->callback(button_callback_oper, in1);
	button_minus->callback(button_callback_oper, in1);
	button_mult->callback(button_callback_oper, in1);
	button_div->callback(button_callback_oper, in1);
	button_answr->callback(button_callback_answr, in1);
	button_back->callback(button_callback_back, in1);
	Fl_Button* button_1 = new Fl_Button(0, 60, 66, 66, "1");
	Fl_Button* button_2 = new Fl_Button(66, 60, 66, 66, "2");
	Fl_Button* button_3 = new Fl_Button(132, 60, 66, 66, "3");
	Fl_Button* button_4 = new Fl_Button(0, 126, 66, 66, "4");
	Fl_Button* button_5 = new Fl_Button(66, 126, 66, 66, "5");
	Fl_Button* button_6 = new Fl_Button(132, 126, 66, 66, "6");
	Fl_Button* button_7 = new Fl_Button(0, 192, 66, 66, "7");
	Fl_Button* button_8 = new Fl_Button(66, 192, 66, 66, "8");
	Fl_Button* button_9 = new Fl_Button(132, 192, 66, 66, "9");
	Fl_Button* button_dot = new Fl_Button(0, 192, 66, 66, ".");
	Fl_Button* button_0 = new Fl_Button(66, 192, 66, 66, "0");
	Fl_Button* button_clear= new Fl_Button(132, 192, 66, 66, "C");
	button_1->callback(button_callback_number, in1);
	button_2->callback(button_callback_number, in1);
	button_3->callback(button_callback_number, in1);
	button_4->callback(button_callback_number, in1);
	button_5->callback(button_callback_number, in1);
	button_6->callback(button_callback_number, in1);
	button_7->callback(button_callback_number, in1);
	button_8->callback(button_callback_number, in1);
	button_9->callback(button_callback_number, in1);
	button_0->callback(button_callback_number, in1);
	button_dot->callback(button_callback_number, in1);
	button_clear->callback(button_callback_clear, in1);
	window->show(argc, argv);

	return Fl::run();
}
