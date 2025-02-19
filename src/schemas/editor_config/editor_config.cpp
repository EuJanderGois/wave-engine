
#include "editor_config.h"
#include <iostream>

using namespace std;

EditorConfig::EditorConfig(const string& filename)
{
    this->loadConfig(filename);
}

void EditorConfig::loadConfig(const string& filename)
{

    YAML::Node configNode = YAML::LoadFile(filename);

    if (configNode["width"]) {
        config.width = configNode["width"].as<int>();
    }
    if (configNode["height"]) {
        config.height = configNode["height"].as<int>();
    }
    if (configNode["version"]) {
        config.version = configNode["version"].as<string>();
    }
    if (configNode["name"]) {
        config.name = configNode["name"].as<string>();
        cout << "Editor Name: " << config.name << endl;
    }
    if (configNode["vsync"]) {
        config.vsync = configNode["vsync"].as<bool>();
    }
    if (configNode["high-dpi"]) {
        config.highDPI = configNode["high-dpi"].as<bool>();
    }
    if (configNode["full-screen"]) {
        config.fullScreen = configNode["full-screen"].as<bool>();
    }
    if (configNode["icon"]) {
        config.icon = configNode["icon"].as<string>();
    }
    if (configNode["target-fps"]) {
        config.targetFPS = configNode["target-fps"].as<int>();
    }
    if (configNode["clear-color"]) {
        config.clearColor = configNode["clear-color"].as<string>();
    }
    if (configNode["default-theme"]) {
        config.defaultTheme = configNode["default-theme"].as<string>();
    }
    if (configNode["default-lang"]) {
        config.defaultLang = configNode["default-lang"].as<string>();
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
