#ifndef H_BUTTON
#define H_BUTTON

#include <string>
#include <functional>
#include "raylib.h"
#include "globals.h"

#define DEFAULT_BG (Color){45, 30, 140, 255}
#define DEFAULT_BG_HOVERED (Color){55, 40, 150, 255}

struct ButtonProperties
{
    float width;
    float height;
    float x;
    float y;
    int segments;
    float cornerRadius;
    Color backgroundColor;
    std::string text;
    float fontSize;
    float spacing;
    Font fontFamily;
    Color textColor;

    ButtonProperties()
        : width(150.0f), height(30.0f), x(100.0f), y(100.0f), segments(8),
          cornerRadius(0.2f), backgroundColor(DEFAULT_BG), text("Button"),
          fontSize(18.0f), spacing(1.0f), fontFamily(jetBrainsMono), textColor(WHITE) {}
};

class Button
{
    private:
        ButtonProperties props;
        std::function<void()> onClickCallback;

    public:
        Button(ButtonProperties properties = ButtonProperties())
        {
            this->props = properties;
        };

        void setOnClick(std::function<void()> callback)
        {
            this->onClickCallback = callback;
        }

        void draw()
        {
            Color backgroundColor = this->isHovered() ? DEFAULT_BG_HOVERED : this->props.backgroundColor;
            DrawRectangleRounded(
                {this->props.x, this->props.y, this->props.width, this->props.height},
                this->props.cornerRadius, this->props.segments, backgroundColor
            );

            Vector2 textSize = MeasureTextEx(this->props.fontFamily, this->props.text.c_str(), this->props.fontSize, this->props.spacing);
            float textPosX, textPosY;
            textPosX = this->props.x + (this->props.width - textSize.x) / 2;
            textPosY = this->props.y + (this->props.height - textSize.y) / 2;
            DrawTextEx(this->props.fontFamily, this->props.text.c_str(), {textPosX, textPosY}, this->props.fontSize, this->props.spacing, this->props.textColor);

            if (this->isHovered() && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
            {
                if (this->onClickCallback)
                {
                    this->onClickCallback();
                }
            }
        }

        bool isHovered()
        {
            int mouseX = GetMouseX();
            int mouseY = GetMouseY();

            bool isHovered = (mouseX >= this->props.x && mouseX <= this->props.x + this->props.width &&
                mouseY >= this->props.y && mouseY <= this->props.y + this->props.height);

            if (isHovered)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};

#endif // H_BUTTON