#pragma once

constexpr int FAIL=-1;

#define RETURN_ERROR(ptr,code){\
    if(ptr==nullptr) return code; }

struct ifont_s;
using ifont = ifont_s;


namespace hello{

class App;
App& GetApp();

class App{
private:
    void Deinit();

    ifont *font_;
    int font_sz_;

public:
    App()
    : 
    font_(nullptr),
    font_sz_(10)
    {}
    ~App(){
        Deinit();
    }
    int OnInit(int font_sz);
    int OnKey(int key_code);
    int OnShow();
    void OnExit();

};

}//exit hello
