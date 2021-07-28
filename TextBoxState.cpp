#include "TextBoxState.h"

TextBoxState::TextBoxState( std::string * FilePath)
{
    m_FilePath = *FilePath;
}

TextBoxState::~TextBoxState()
{
    //dtor
}
bool TextBoxState::OnEnter()
{
    std::ifstream ifs;
    ifs.open(m_FilePath.c_str(),std::ios::in);
    while(!ifs.eof())
    {
        std::string tempstring;
        ifs >> tempstring;
        m_curText << tempstring;
        m_curText << " ";
    }

    std::cout << m_curText.str() << " : Resume\n";
    std::cout << GetStateID() << " : Resume\n";
}
bool TextBoxState::onExit()
{
    std::cout << GetStateID() << " : onEnter\n\n";
}
void TextBoxState::resume()
{
    std::cout << GetStateID() << " : onExit\n";
}
