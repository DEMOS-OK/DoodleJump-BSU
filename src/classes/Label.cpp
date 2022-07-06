#include "Label.h";

Label::Label()
{

}

/// <summary>
/// Конструктор класса Label
/// </summary>
/// <param name="fontName"> обязательный параметр </param>
/// <param name="labelText"> обязательный параметр </param>
/// <param name="posX"> необязательный параметр </param>
/// <param name="posY"> необязательный параметр </param>
/// <param name="fontSize"> необязательный параметр </param>
/// <param name="color"> необязательный параметр </param>
/// <param name="textStyle"> необязательный параметр </param>
Label::Label(string fontPath, string labelText, float posX, float posY, int fontSize,
	Color color, Text::Style textStyle)
{
	font.loadFromFile(fontPath);

	// Устанавливаем шрифт
	text.setFont(font);

	// Устанавливаем отображаемый текст
	text.setString(labelText);

	// Устанавливаем размер шрифта
	text.setCharacterSize(fontSize);

	// Устанавливаем цвет шрифта
	text.setFillColor(color);

	// Устанавливаем стиль текста
	text.setStyle(textStyle);

	// Устанавливаем позицию текста
	text.setPosition(posX, posY);
}

/// <summary>
/// Устанавливает позицию метки на экране
/// </summary>
/// <param name="posX"></param>
/// <param name="posY"></param>
void Label::setPosition(float posX, float posY)
{
	text.setPosition(posX, posY);
}

/// <summary>
/// Устанавливает шрифт
/// </summary>
/// <param name="fontPath"></param>
void Label::setFont(string fontPath)
{
	font.loadFromFile(fontPath);
	text.setFont(font);
}

/// <summary>
/// Устанавливает цвет метки
/// </summary>
/// <param name="color"></param>
void Label::setColor(Color color)
{
	// Устанавливаем цвет шрифта
	text.setFillColor(color);
}

/// <summary>
/// Устанавливает размер шрифта метки
/// </summary>
/// <param name="fontSize"></param>
void Label::setCharacterSize(int fontSize)
{
	text.setCharacterSize(fontSize);
}

/// <summary>
/// Устанавливает стили метки
/// </summary>
/// <param name="textStyle"></param>
void Label::setStyle(Text::Style textStyle)
{
	text.setCharacterSize(textStyle);
}

/// <summary>
/// Устанавливает текстовое содержимое метки
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