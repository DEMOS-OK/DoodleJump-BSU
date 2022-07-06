#include "Label.h";

Label::Label()
{

}

/// <summary>
/// ����������� ������ Label
/// </summary>
/// <param name="fontName"> ������������ �������� </param>
/// <param name="labelText"> ������������ �������� </param>
/// <param name="posX"> �������������� �������� </param>
/// <param name="posY"> �������������� �������� </param>
/// <param name="fontSize"> �������������� �������� </param>
/// <param name="color"> �������������� �������� </param>
/// <param name="textStyle"> �������������� �������� </param>
Label::Label(string fontPath, string labelText, float posX, float posY, int fontSize,
	Color color, Text::Style textStyle)
{
	font.loadFromFile(fontPath);

	// ������������� �����
	text.setFont(font);

	// ������������� ������������ �����
	text.setString(labelText);

	// ������������� ������ ������
	text.setCharacterSize(fontSize);

	// ������������� ���� ������
	text.setFillColor(color);

	// ������������� ����� ������
	text.setStyle(textStyle);

	// ������������� ������� ������
	text.setPosition(posX, posY);
}

/// <summary>
/// ������������� ������� ����� �� ������
/// </summary>
/// <param name="posX"></param>
/// <param name="posY"></param>
void Label::setPosition(float posX, float posY)
{
	text.setPosition(posX, posY);
}

/// <summary>
/// ������������� �����
/// </summary>
/// <param name="fontPath"></param>
void Label::setFont(string fontPath)
{
	font.loadFromFile(fontPath);
	text.setFont(font);
}

/// <summary>
/// ������������� ���� �����
/// </summary>
/// <param name="color"></param>
void Label::setColor(Color color)
{
	// ������������� ���� ������
	text.setFillColor(color);
}

/// <summary>
/// ������������� ������ ������ �����
/// </summary>
/// <param name="fontSize"></param>
void Label::setCharacterSize(int fontSize)
{
	text.setCharacterSize(fontSize);
}

/// <summary>
/// ������������� ����� �����
/// </summary>
/// <param name="textStyle"></param>
void Label::setStyle(Text::Style textStyle)
{
	text.setCharacterSize(textStyle);
}

/// <summary>
/// ������������� ��������� ���������� �����
/// </summary>
/// <param name="labelText"></param>
void Label::setText(string labelText)
{
	text.setString(labelText);
}

Text* Label::getText()
{
	return &text;
}