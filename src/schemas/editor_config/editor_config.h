
#ifndef CONFIG_H
#define CONFIG_H

#include <string>
#include "yaml-cpp/yaml.h"

using namespace std;

struct EditorConfigSchema
{
    int width;              // Largura da janela
    int height;             // Altura da janela
    string version;         // Versão do editor
    string name;            // Nome do editor
    bool vsync;             // Sincronização vertical
    bool highDPI;           // Alta DPI
    bool fullScreen;        // Modo de tela cheia
    string icon;            // Ícone do editor
    int targetFPS;          // FPS alvo
    string clearColor;      // Cor de limpeza
    string defaultTheme;    // Tema padrão
    string defaultLang;     // Idioma padrão
};

class EditorConfig
{
    private:
    EditorConfigSchema config;

    public:

    EditorConfig(const string& filename);

    void loadConfig(const string& filename);

    // Getters
    int getWidth() const;
    int getHeight() const;
    string getVersion() const;
    string getName() const;
    bool isVsync() const;
    bool isHighDPI() const;
    bool isFullScreen() const;
    string getIcon() const;
    int getTargetFPS() const;
    string getClearColor() const;
    string getDefaultTheme() const;
    string getDefaultLang() const;

    // Setters
    void setWidth(int w);
    void setHeight(int h);
    void setVersion(const string& v);
    void setName(const string& n);
    void setVsync(bool v);
    void setHighDPI(bool h);
    void setFullScreen(bool f);
    void setIcon(const std::string& i);
    void setTargetFPS(int fps);
    void setClearColor(const string& color);
    void setDefaultTheme(const string& theme);
    void setDefaultLang(const string& lang);
};


#endif
