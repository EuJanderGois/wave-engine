
#include "editor_config.h"
#include <iostream>

using namespace std;

EditorConfig::EditorConfig(const string& filename)
{
    YAML::Node configNode = YAML::LoadFile(filename);

    if (configNode["editor"]["width"]) {
        this->config.width = configNode["editor"]["width"].as<int>();
    }
    if (configNode["editor"]["height"]) {
        this->config.height = configNode["editor"]["height"].as<int>();
    }
    if (configNode["editor"]["version"]) {
        this->config.version = configNode["editor"]["version"].as<string>();
    }
    if (configNode["editor"]["name"]) {
        this->config.name = configNode["editor"]["name"].as<string>();
        cout << "Editor Name: " << config.name << endl;
    }
    if (configNode["editor"]["vsync"]) {
        this->config.vsync = configNode["editor"]["vsync"].as<bool>();
    }
    if (configNode["editor"]["high-dpi"]) {
        this->config.highDPI = configNode["editor"]["high-dpi"].as<bool>();
    }
    if (configNode["editor"]["full-screen"]) {
        this->config.fullScreen = configNode["editor"]["full-screen"].as<bool>();
    }
    if (configNode["editor"]["icon"]) {
        this->config.icon = configNode["editor"]["icon"].as<string>();
    }
    if (configNode["editor"]["target-fps"]) {
        this->config.targetFPS = configNode["editor"]["target-fps"].as<int>();
    }
    if (configNode["editor"]["clear-color"]) {
        this->config.clearColor = configNode["editor"]["clear-color"].as<string>();
    }
    if (configNode["editor"]["default-theme"]) {
        this->config.defaultTheme = configNode["editor"]["default-theme"].as<string>();
    }
    if (configNode["editor"]["default-lang"]) {
        this->config.defaultLang = configNode["editor"]["default-lang"].as<string>();
    }
}

// Getters
int EditorConfig::getWidth() const { return config.width; }
int EditorConfig::getHeight() const { return config.height; }
string EditorConfig::getVersion() const { return config.version; }
string EditorConfig::getName() const { return config.name; }
bool EditorConfig::isVsync() const { return config.vsync; }
bool EditorConfig::isHighDPI() const { return config.highDPI; }
bool EditorConfig::isFullScreen() const { return config.fullScreen; }
string EditorConfig::getIcon() const { return config.icon; }
int EditorConfig::getTargetFPS() const { return config.targetFPS; }
string EditorConfig::getClearColor() const { return config.clearColor; }
string EditorConfig::getDefaultTheme() const { return config.defaultTheme; }
string EditorConfig::getDefaultLang() const { return config.defaultLang; }

// Setters
void EditorConfig::setWidth(int w) { config.width = w; }
void EditorConfig::setHeight(int h) { config.height = h; }
void EditorConfig::setVersion(const string& v) { config.version = v; }
void EditorConfig::setName(const string& n) { config.name = n; }
void EditorConfig::setVsync(bool v) { config.vsync = v; }
void EditorConfig::setHighDPI(bool h) { config.highDPI = h; }
void EditorConfig::setFullScreen(bool f) { config.fullScreen = f; }
void EditorConfig::setIcon(const string& i) { config.icon = i; }
void EditorConfig::setTargetFPS(int fps) { config.targetFPS = fps; }
void EditorConfig::setClearColor(const string& color) { config.clearColor = color; }
void EditorConfig::setDefaultTheme(const string& theme) { config.defaultTheme = theme; }
void EditorConfig::setDefaultLang(const string& lang) { config.defaultLang = lang; }
