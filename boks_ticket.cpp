#include <fstream> // 파일에 대한 입출력을 지원하는 클래스 | ifstream 클래스 등
#include <string> // 문자열 클래스 | string 객체, getline() 함수 등
#include <iostream> // 입출력 헤더 파일 | cin 객체 등
#include <sstream> // 문자열 스트림 클래스| stringstream 등 
#include <unistd.h>  // 유닉스 사용 라이브러리 | sleep 등 함수

using std::ifstream; using std::ofstream; using std::ios;// 파일을 프로그램에 입력, 프로그램이 파일에 입력, 파일 모드 플래그 사용
using std::cout; using std::endl; using std::cin; using std::string;// cout(출력), endl(개행), cin(입력), string(문자열) 사용
using std::stringstream; using std::to_string; // 입력 문자열 데이터 읽는 것에 사용, 문자열로 바꿔주는데 사용

struct screen_key_number // 입력 숫자 구조체
{
    char num1; // 첫 화면 숫자
    char num2; // 경기 예매 숫자
    char num3; // 로그인 숫자
    char num4; // 예매 구역 선택 숫자
}sc;

struct enter_number // 엔터키 위한 구조체
{
    char enter; // 엔터키
}eno;

struct signup_user // 가입하려는 유저 구조체 및 인원과 결제 관련 구조체
{
    int judge; // 중복 판단 값
    string uid; // 아이디
    string upw; // 비밀번호
    string umail; // 메일
    string uphnum; // 휴대폰 번호
    int user_num = 0; // 회원번호
    int p_num = 0; // 인원 수
    int s_num = 0; // 좌석번호
    int count = 0; // 남은 사람 수
    string seat; // 좌석 값
    int fin; // 최종 결제 확인
}sg;

struct saved_user // 가입된 유저 구조체
{   
    string all;
    string id;
    string pw;
    string mail;
    string phnum;
    string usernum;
}svd;

struct find_user // 유저 찾기 및 로그인하려는 유저 구조체
{   
    string fid;
    string fmail;
    string fpw;
}fd;

struct price // 구역별 가격
{
    int MVIP = 80000;
    int VIP = 40000;
    int GOLD = 20000;
    int SILVER = 10000;
}pr;

struct exit // 종료하는 값 구조체
{
    int it = 0;
}ex;

// 메인 함수
int main()
{
    ifstream cup_in("txt_flie/afc_cup.txt"); // 컵 파일을 프로그램에 입력
    string printf; // 출력용 문자열
    
        if(!cup_in.is_open())
        {
            cout << "컵 이미지 파일을 찾을 수 없습니다." << endl;

            return 0;
        } // 컵 파일을 못 찾을 시에 출력

        while(cup_in)
        {
            getline(cup_in, printf);
            cout << printf << endl;
        } // 컵 파일을 문자열 printf에 넣어 읽고 출력
        cup_in.close(); // 컵 파일 닫음

    cout << "                     2023 AFC 카타르 아시안컵" << endl;
    cout << "카타르 아시안컵 기간: 2024년 1월 12일(금)~2024년 2월 10일(일)(현지기준)" << endl;
    cout << "카타르 아시안컵 개최지: 카타르 도하, 알 와크라, 알 라이얀, 알코르" << endl;
    cout << "카타르 아시안컵 중계: tvN, tvN SPORTS, 쿠팡 플레이" << endl << endl; // 아시안컵 정보
        
    cout << "Bok's Ticket과 연결된 여러분을 환영합니다!" << endl; // 시작전 문구

    while(1) // 프로그램 선택 시작
    {
        ex.it = 0;
        cout << "\n1. 참가국 및 조별 정보 2. 조별 경기일정 3. 한국 감독/선수 명단, 선수 정보" << endl;
        cout << "4. 경기 예매" << endl; // 기능 메뉴
        cout << "원하시는 서비스를 입력해주세요: ";
        cin >> sc.num1; // 메뉴 번호 받기
        cout << endl;

        switch(sc.num1) // 첫 메뉴 선택 후
        {
            case '1': // 참가국 및 조별 정보
            {
                cout << "참가국은 다음과 같습니다." << endl;
                ifstream play_country("txt_flie/pl_co.txt"); // 해당경로의 텍스트파일을 읽기위해 열음 ios::in이 기본값
                
                if(!play_country.is_open())
                {
                    cout << "참가국 정보가 없습니다." << endl;
                } // 파일이 없으면 없다고 출력

                while(play_country)
                {
                    getline(play_country, printf);
                    cout << printf << endl;
                } // getline의 첫 번째 매개변수를 두 번째 매개변수에 저장 / 출력
                play_country.close(); // 파일 닫기

                cout << "엔터키를 누르면 돌아갑니다.";
                cin.get(eno.enter); // 엔터키를 받기
                cin.ignore(100,'\n'); // 엔터키전의 입력값은 무시
                if(eno.enter == '\n')
                {   
                    system("clear"); // 화면 지우기
                    break;
                }
            }

            case '2': // 조별 경기일정
            {
                cout << "조별 경기일정은 다음과 같습니다." << endl;
                cout << endl;
                ifstream play_date("txt_flie/pl_day.txt");
                    
                if(!play_date.is_open())
                {
                    cout << "조별 경기일정 정보가 없습니다." << endl;
                }

                while(play_date)
                {
                    getline(play_date, printf);
                    cout << printf << endl;
                }
                play_date.close();

                cout << "엔터키를 누르면 돌아갑니다.";
                cin.get(eno.enter);
                cin.ignore(100,'\n');
                if(eno.enter == '\n')
                {   
                    system("clear");
                    break;
                }
            }

            case '3': // 한국 감독/선수 명단, 선수 정보
            {
                cout << "한국 감독/선수 명단, 선수 정보은 다음과 같습니다." << endl;
                cout << endl;
                ifstream info_korea("txt_flie/pl_korea.txt");
                    
                if(!info_korea.is_open())
                {
                    cout << "한국 정보가 없습니다." << endl;
                }

                while(info_korea)
                {
                    getline(info_korea, printf);
                    cout << printf << endl;
                }
                info_korea.close();

                cout << "엔터키를 누르면 돌아갑니다.";
                cin.get(eno.enter);
                cin.ignore(100,'\n');
                if(eno.enter == '\n')
                {   
                    system("clear");
                    break;
                }
            }
            
            case '4': // 경기 예매
            {
                system("clear");
                cout << "경기 예매 페이지에 오신 것을 환영합니다!" << endl;
                while(sc.num1 == '4') // 경기 예매 동안
                {
                    if(ex.it == 1)
                    {
                        break;
                    }

                    system("clear");
                    cout << "1. 회원가입 2. 로그인" << endl;
                    cout << "원하시는 서비스를 입력해주세요: ";
                    cin >> sc.num2; // 경기 예매 메뉴 선택 받기
                    cout << endl;

                    switch(sc.num2) // 경기 예매 메뉴 선택
                    {
                        case '1': // 회원가입
                        {
                            cout << "회원가입 페이지입니다." << endl;

                            while(1) // 아이디 + 중복체크
                            {
                                ifstream user_check("csv_file/user_info.csv");

                                cout << "아이디를 입력하세요: ";
                                cin >> sg.uid;
                                sg.judge = 0; // 중복 판단 값

                                while(getline(user_check, svd.all)) // user_check으로 읽은 파일 svd.all 스트링에 저장
                                {
                                    stringstream user(svd.all); // 문자열을 user로 토큰화함
                                    getline(user, svd.id, ','); // ,를 기준으로 svd.id에 넣음

                                    if(svd.id == sg.uid)
                                    {
                                        cout << "중복된 아이디 입니다. 다시 시도하세요!" << endl;
                                        sleep(1);
                                        system("clear");
                                        sg.judge++;
                                        break;
                                    }
                                }
                                user_check.close();
                                if(sg.judge == 0)
                                {
                                    break;
                                }
                            } // 아이디 + 중복체크

                            while(1)  // 비밀번호 + 제한
                            {
                                ifstream user_check("csv_file/user_info.csv");
                                
                                cout << endl;
                                cout << "비밀번호는 5자리이상 11자리미만으로 가능합니다." << endl;
                                cout << "비밀번호를 입력하세요: ";
                                cin >> sg.upw;

                                if(sg.upw.length() >= 5 && sg.upw.length() < 11)
                                {
                                    break;
                                }
                                else
                                {
                                    cout << "자릿수가 조건에 맞지않습니다. 다시 입력하세요!" << endl;
                                    sleep(1);
                                    system("clear");
                                }
                            } // 비밀번호 + 제한

                            while(1) // 이메일 + 중복체크
                            {
                                ifstream user_check("csv_file/user_info.csv");

                                cout << "이메일을 입력하세요: ";
                                cin >> sg.umail;
                                sg.judge = 0; // 중복 판단 값

                                while(getline(user_check, svd.all)) // user_check으로 읽은 파일 svd.all 스트링에 저장
                                {
                                    stringstream user(svd.all); // 문자열을 user로 토큰화함
                                    getline(user, svd.id, ','); // ,를 기준으로 svd.id에 넣음
                                    getline(user, svd.pw, ',');
                                    getline(user, svd.mail, ',');

                                    if(svd.mail == sg.umail)
                                    {
                                        cout << "중복된 이메일입니다. 다시 시도하세요!" << endl;
                                        sleep(1);
                                        system("clear");
                                        sg.judge++;
                                        break;
                                    }
                                }
                                user_check.close();
                                if(sg.judge == 0)
                                {
                                    break;
                                }
                            } // 이메일 + 중복체크

                            while(1) // 휴대폰 번호 + 중복체크
                            {
                                ifstream user_check("csv_file/user_info.csv");

                                cout << "휴대폰 번호를 입력하세요: ";
                                cin >> sg.uphnum;
                                sg.judge = 0; // 중복 판단 값

                                while(getline(user_check, svd.all)) // user_check으로 읽은 파일 svd.all 스트링에 저장
                                {
                                    stringstream user(svd.all); // 문자열을 user로 토큰화함
                                    getline(user, svd.id, ','); // ,를 기준으로 svd.id에 넣음
                                    getline(user, svd.pw, ',');
                                    getline(user, svd.mail, ',');
                                    getline(user, svd.phnum, ',');

                                    if(svd.phnum == sg.uphnum)
                                    {
                                        cout << "중복된 번호입니다. 다시 시도하세요!" << endl;
                                        sleep(1);
                                        system("clear");
                                        sg.judge++;
                                        break;
                                    }
                                }
                                user_check.close();
                                if(sg.judge == 0)
                                {
                                    break;
                                }
                            } // 휴대폰 번호 + 중복체크

                            ofstream user_sign("csv_file/user_info.csv", ios::app);

                            system("clear");
                            cout << "회원가입을 축하합니다!" << endl;
                            cout << endl;
                            sg.user_num++;
                            user_sign << sg.uid << ',' << sg.upw << ',' << sg.umail << ',' << sg.uphnum << ',' << sg.user_num << '\n';
                            cout << "고객님의 회원번호는 " << sg.user_num << "입니다." << endl;
                            cout << endl;

                            cout << "엔터키를 누르면 돌아갑니다.";
                            cin.get(eno.enter);
                            cin.ignore(100,'\n');
                            if(eno.enter == '\n')
                            {   
                                system("clear");
                                break;
                            }

                        } // switch(sc.num2)의 case '1' // 회원가입

                        case '2': // 로그인
                        {
                            system("clear");
                            cout << "회원이시군요! 로그인 페이지로 오신 것을 환영합니다!" << endl;
                            while(sc.num2 == '2') // 로그인 동안
                            {
                                if(ex.it == 1)
                                {
                                    break;
                                }
                                
                                system("clear");
                                cout << "1. 아이디 찾기 2. 비밀번호 찾기 3. 로그인" << endl;
                                cout << "메뉴를 선택해주세요: ";
                                cin >> sc.num3;
                                cout << endl;

                                switch(sc.num3) // 로그인  메뉴 선택
                                {   
                                    case '1': // 아이디 찾기
                                    {
                                        while(1) // 아이디 찾는 동안
                                        {
                                            ifstream user_check("csv_file/user_info.csv");

                                            cout << "아이디 찾기 페이지입니다." << endl;
                                            cout << "이메일을 입력해주세요: ";
                                            cin >> fd.fmail;
                                            sg.judge = 0; // 오류 판단 값

                                            while(getline(user_check, svd.all))
                                            {
                                                stringstream user(svd.all);
                                                getline(user, svd.id, ',');
                                                getline(user, svd.pw, ',');
                                                getline(user, svd.mail, ',');

                                                if(svd.mail == fd.fmail)
                                                {
                                                    cout << "가입되신 아이디는 " << svd.id << "입니다." << endl;
                                                    cout << endl;

                                                    sg.judge++;
                                                    
                                                    cout << "엔터키를 누르면 돌아갑니다.";
                                                    cin.get(eno.enter);
                                                    cin.ignore(100,'\n');
                                                    if(eno.enter == '\n')
                                                    {   
                                                        system("clear");
                                                        break;
                                                    }
                                                }
                                            }
                                            user_check.close();
                                            if(sg.judge == 0)
                                            {
                                                cout << "가입되신 계정이 없거나 이메일이 틀렸습니다."<< endl;
                                                cout << endl;
                                                cout << "엔터키를 누르면 돌아갑니다.";
                                                cin.get(eno.enter);
                                                cin.ignore(100,'\n');
                                                if(eno.enter == '\n')
                                                {   
                                                    system("clear");
                                                    break;
                                                }
                                            }
                                            break;
                                        } // while(1) // 아이디 찾는 동안
                                        break;
                                    } // case '1': // 아이디 찾기

                                    case '2': // 비밀번호 찾기
                                    {
                                        while(1) // 비밀번호 찾는 동안
                                        {
                                            ifstream user_check("csv_file/user_info.csv");

                                            cout << "비밀번호 찾기 페이지입니다." << endl;
                                            cout << "아이디를 입력해주세요: ";
                                            cin >> fd.fid;
                                            cout << "이메일을 입력해주세요: ";
                                            cin >> fd.fmail;
                                            sg.judge = 0; // 오류 판단 값

                                            while(getline(user_check, svd.all))
                                            {
                                                stringstream user(svd.all);
                                                getline(user, svd.id, ',');
                                                getline(user, svd.pw, ',');
                                                getline(user, svd.mail, ',');

                                                if(svd.id == fd.fid && svd.mail == fd.fmail)
                                                {
                                                    cout << "가입되신 비밀번호는 " << svd.pw << "입니다."<< endl;
                                                    cout << endl;

                                                    sg.judge++;

                                                    cout << "엔터키를 누르면 돌아갑니다.";
                                                    cin.get(eno.enter);
                                                    cin.ignore(100,'\n');
                                                    if(eno.enter == '\n')
                                                    {   
                                                    system("clear");
                                                    break;
                                                    }
                                                }
                                            }
                                            user_check.close();
                                            if(sg.judge == 0)
                                            {
                                                cout << "가입되신 계정이 없거나 입력하신 게 틀렸습니다." << endl;
                                                cout << endl;
                                                cout << "엔터키를 누르면 돌아갑니다.";
                                                cin.get(eno.enter);
                                                cin.ignore(100,'\n');
                                                if(eno.enter == '\n')
                                                {   
                                                    system("clear");
                                                    break;
                                                }
                                            }
                                            break;
                                        } // while(1) // 비밀번호 찾는 동안
                                        break;
                                    } // case '2': // 비밀번호 찾기

                                    case '3': // 3. 로그인
                                    {
                                        while(1) // 3. 로그인 하는 동안
                                        {
                                            ifstream user_check("csv_file/user_info.csv");

                                            cout << "로그인 페이지입니다." << endl;
                                            cout << "아이디를 입력해주세요: ";
                                            cin >> fd.fid;
                                            cout << "비밀번호를 입력해주세요: ";
                                            cin >> fd.fpw;
                                            sg.judge = 0; // 오류 판단 값

                                            while(getline(user_check, svd.all)) // 로그인
                                            {
                                                stringstream user(svd.all);
                                                getline(user, svd.id, ',');
                                                getline(user, svd.pw, ',');

                                                if(svd.id == fd.fid && svd.pw == fd.fpw) // 아이디&비밀번호 일치
                                                {
                                                    cout << "로그인 중입니다.."<< endl;
                                                    sleep(1);
                                                    system("clear");
                                                    cout << "어서오세요! " << fd.fid << "님" << endl;
                                                    cout << endl;
                                                    sg.judge++;

                                                    while(1) // 로그인 성공 동안
                                                    {
                                                        if(ex.it == 1)
                                                        {
                                                            break;
                                                        }
                                                        
                                                        ifstream lv_sel("txt_flie/lv_all.txt");
                                                        
                                                        if(!lv_sel.is_open())
                                                        {
                                                            cout << "구역 이미지 파일을 찾을 수 없습니다." << endl;
                                                        }
                                                            
                                                        while(lv_sel)
                                                        {
                                                            getline(lv_sel, printf);
                                                            cout << printf << endl;
                                                        }
                                                        lv_sel.close();
                                                        
                                                        cout << "원하시는 구역을 선택하세요: ";
                                                        cin >> sc.num4;
                                                        cout << endl;

                                                        switch(sc.num4) // 구역 선택 동안
                                                        {
                                                            case '1': // MVIP - A열 선택 동안
                                                            {
                                                                cout << "MVIP A열을 선택하셨습니다." << endl;
                                                                cout << endl;
                                                                ifstream lv_MVIP("txt_flie/lv_MVIP.txt");

                                                                if(!lv_MVIP.is_open())
                                                                {
                                                                    cout << "MVIP 구역을 불러올 수 없습니다." << endl;
                                                                }

                                                                while(lv_MVIP)
                                                                {
                                                                    getline(lv_MVIP, printf);
                                                                    cout << printf << endl;
                                                                }
                                                                lv_MVIP.close();
                                                                

                                                                cout << "인원 수를 입력하세요: ";
                                                                cin >> sg.p_num;
                                                                
                                                                if(sg.p_num > 0 && sg.p_num < 11) // 인원 수 오류 체크
                                                                {
                                                                    system("clear");
                                                                    ifstream lv_MVIP("txt_flie/lv_MVIP.txt");

                                                                    if(!lv_MVIP.is_open())
                                                                    {
                                                                        cout << "MVIP 구역을 불러올 수 없습니다." << endl;
                                                                    }

                                                                    while(lv_MVIP)
                                                                    {
                                                                        getline(lv_MVIP, printf);
                                                                        cout << printf << endl;
                                                                    }
                                                                    lv_MVIP.close();

                                                                    cout << "고르신 인원수는 " << sg.p_num << "명 입니다." << endl;
                                                                    cout << endl;
                                                                    

                                                                   while(sg.count != sg.p_num) // 인원 수 일치 체크
                                                                   {
                                                                        cout << "좌석 번호를 골라주세요: ";
                                                                        cin >> sg.s_num;
                                                                        
                                                                        if(sg.s_num > 0 && sg.s_num < 11)
                                                                        {
                                                                            cout << "고르신 좌석은 A열 " << sg.s_num << " 번좌석입니다." << endl;
                                                                            cout << endl;
                                                                            sg.seat += to_string(sg.s_num);
                                                                            sg.seat += "번 ";
                                                                            sg.count++;
                                                                        }

                                                                        else
                                                                        {
                                                                            cout << "잘못된 입력입니다." << endl;
                                                                            cin.clear();
                                                                            cout << endl;
                                                                            cin.ignore(100,'\n');
                                                                        }
                                                                    } // while(sg.count == sg.p_num) // 인원 수 일치 체크

                                                                    cout << "고르신 좌석은 A열 " << sg.seat << "좌석입니다." << endl;
                                                                    cout << "가격은 " << pr.MVIP * sg.p_num << "원입니다." << endl;
                                                                    cout << endl;
                                                                    cout << "결제를 원하시면 1을, 돌아가시려면 0을 눌러주세요: ";
                                                                    cin >> sg.fin;

                                                                    if(sg.fin == 1)
                                                                    {
                                                                        system("clear");

                                                                        cout << "결제 완료!" << endl;
                                                                        cout << endl;
                                                                        cout << "결제하신 좌석은 A열 " << sg.seat << "좌석입니다." << endl;
                                                                        cout << "이용해주셔서 감사합니다!" << endl;
                                                                        cout << endl;

                                                                        sleep(5);
                                                                        ex.it++;

                                                                        cout << "엔터키를 누르면 돌아갑니다.";
                                                                        cin.get(eno.enter);
                                                                        cin.ignore(100,'\n');
                                                                        if(eno.enter == '\n')
                                                                        {   
                                                                            system("clear");
                                                                            break;
                                                                        }
                                                                    }
                                                                    
                                                                    else if(sg.fin == 0)
                                                                    {
                                                                        sg.p_num = 0;
                                                                        sg.s_num = 0;
                                                                        sg.count = 0;
                                                                        sg.seat.erase(0, 100);
                                                                        system("clear");
                                                                        break;
                                                                    }

                                                                    else
                                                                    {
                                                                        sg.p_num = 0;
                                                                        sg.s_num = 0;
                                                                        sg.count = 0;
                                                                        sg.seat.erase(0, 100);
                                                                        
                                                                        system("clear");
                                                                        cout << "잘못된 입력입니다. 구역 선택으로 돌아갑니다."<< endl;
                                                                        cin.clear();
                                                                        cout << endl;
                                                                        sleep(10);
                                                                        cin.ignore(100, '\n');
                                                                        break;
                                                                    }

                                                                } // if(sg.p_num > 0 && sg.p_num < 11) // 인원 수 오류 체크

                                                                else
                                                                {
                                                                    cout << "잘못된 입력입니다. 구역 선택으로 돌아갑니다."<< endl;
                                                                    cin.clear();
                                                                    cout << endl;
                                                                    sleep(2);
                                                                    cin.ignore(100, '\n');
                                                                    system("clear");
                                                                    break;
                                                                }

                                                            } // case '1': // MVIP - A열 선택 동안

                                                            case '2': // VIP - B열 선택 동안
                                                            {
                                                                cout << "VIP B열을 선택하셨습니다." << endl;
                                                                cout << endl;
                                                                ifstream lv_VIP("txt_flie/lv_VIP.txt");

                                                                if(!lv_VIP.is_open())
                                                                {
                                                                    cout << "VIP 구역을 불러올 수 없습니다." << endl;
                                                                }

                                                                while(lv_VIP)
                                                                {
                                                                    getline(lv_VIP, printf);
                                                                    cout << printf << endl;
                                                                }
                                                                lv_VIP.close();
                                                                

                                                                cout << "인원 수를 입력하세요: ";
                                                                cin >> sg.p_num;
                                                                
                                                                if(sg.p_num > 0 && sg.p_num < 11) // 인원 수 오류 체크
                                                                {
                                                                    system("clear");
                                                                    ifstream lv_VIP("txt_flie/lv_VIP.txt");

                                                                    if(!lv_VIP.is_open())
                                                                    {
                                                                        cout << "VIP 구역을 불러올 수 없습니다." << endl;
                                                                    }

                                                                    while(lv_VIP)
                                                                    {
                                                                        getline(lv_VIP, printf);
                                                                        cout << printf << endl;
                                                                    }
                                                                    lv_VIP.close();

                                                                    cout << "고르신 인원수는 " << sg.p_num << "명 입니다." << endl;
                                                                    cout << endl;
                                                                    

                                                                   while(sg.count != sg.p_num) // 인원 수 일치 체크
                                                                   {
                                                                        cout << "좌석 번호를 골라주세요: ";
                                                                        cin >> sg.s_num;
                                                                        
                                                                        if(sg.s_num > 0 && sg.s_num < 11)
                                                                        {
                                                                            cout << "고르신 좌석은 B열 " << sg.s_num << " 번좌석입니다." << endl;
                                                                            cout << endl;
                                                                            sg.seat += to_string(sg.s_num);
                                                                            sg.seat += "번 ";
                                                                            sg.count++;
                                                                        }

                                                                        else
                                                                        {
                                                                            cout << "잘못된 입력입니다." << endl;
                                                                            cin.clear();
                                                                            cout << endl;
                                                                            cin.ignore(100,'\n');
                                                                        }
                                                                    } // while(sg.count == sg.p_num) // 인원 수 일치 체크

                                                                    cout << "고르신 좌석은 B열 " << sg.seat << "좌석입니다." << endl;
                                                                    cout << "가격은 " << pr.VIP * sg.p_num << "원입니다." << endl;
                                                                    cout << endl;
                                                                    cout << "결제를 원하시면 1을, 돌아가시려면 0을 눌러주세요: ";
                                                                    cin >> sg.fin;

                                                                    if(sg.fin == 1)
                                                                    {
                                                                        system("clear");

                                                                        cout << "결제 완료!" << endl;
                                                                        cout << endl;
                                                                        cout << "결제하신 좌석은 B열 " << sg.seat << "좌석입니다." << endl;
                                                                        cout << "이용해주셔서 감사합니다!" << endl;
                                                                        cout << endl;

                                                                        sleep(5);
                                                                        ex.it++;

                                                                        cout << "엔터키를 누르면 돌아갑니다.";
                                                                        cin.get(eno.enter);
                                                                        cin.ignore(100,'\n');
                                                                        if(eno.enter == '\n')
                                                                        {   
                                                                            system("clear");
                                                                            break;
                                                                        }
                                                                    }
                                                                    
                                                                    else if(sg.fin == 0)
                                                                    {
                                                                        sg.p_num = 0;
                                                                        sg.s_num = 0;
                                                                        sg.count = 0;
                                                                        sg.seat.erase(0, 100);
                                                                        system("clear");
                                                                        break;
                                                                    }

                                                                    else
                                                                    {
                                                                        sg.p_num = 0;
                                                                        sg.s_num = 0;
                                                                        sg.count = 0;
                                                                        sg.seat.erase(0, 100);

                                                                        system("clear");
                                                                        cout << "잘못된 입력입니다. 구역 선택으로 돌아갑니다."<< endl;
                                                                        cin.clear();
                                                                        cout << endl;
                                                                        sleep(10);
                                                                        cin.ignore(100, '\n');
                                                                        break;
                                                                    }

                                                                } // if(sg.p_num > 0 && sg.p_num < 11) // 인원 수 오류 체크

                                                                else
                                                                {
                                                                    cout << "잘못된 입력입니다. 구역 선택으로 돌아갑니다."<< endl;
                                                                    cin.clear();
                                                                    cout << endl;
                                                                    sleep(2);
                                                                    cin.ignore(100, '\n');
                                                                    system("clear");
                                                                    break;
                                                                }

                                                            } // case '2': // VIP - B열 선택 동안

                                                            case '3': // GOLD - C열 선택 동안
                                                            {
                                                                cout << "GOLD C열을 선택하셨습니다." << endl;
                                                                cout << endl;
                                                                ifstream lv_GOLD("txt_flie/lv_GOLD.txt");

                                                                if(!lv_GOLD.is_open())
                                                                {
                                                                    cout << "GOLD 구역을 불러올 수 없습니다." << endl;
                                                                }

                                                                while(lv_GOLD)
                                                                {
                                                                    getline(lv_GOLD, printf);
                                                                    cout << printf << endl;
                                                                }
                                                                lv_GOLD.close();
                                                                

                                                                cout << "인원 수를 입력하세요: ";
                                                                cin >> sg.p_num;
                                                                
                                                                if(sg.p_num > 0 && sg.p_num < 11) // 인원 수 오류 체크
                                                                {
                                                                    system("clear");
                                                                    ifstream lv_GOLD("txt_flie/lv_GOLD.txt");

                                                                    if(!lv_GOLD.is_open())
                                                                    {
                                                                        cout << "GOLD 구역을 불러올 수 없습니다." << endl;
                                                                    }

                                                                    while(lv_GOLD)
                                                                    {
                                                                        getline(lv_GOLD, printf);
                                                                        cout << printf << endl;
                                                                    }
                                                                    lv_GOLD.close();

                                                                    cout << "고르신 인원수는 " << sg.p_num << "명 입니다." << endl;
                                                                    cout << endl;
                                                                    

                                                                   while(sg.count != sg.p_num) // 인원 수 일치 체크
                                                                   {
                                                                        cout << "좌석 번호를 골라주세요: ";
                                                                        cin >> sg.s_num;
                                                                        
                                                                        if(sg.s_num > 0 && sg.s_num < 11)
                                                                        {
                                                                            cout << "고르신 좌석은 C열 " << sg.s_num << " 번좌석입니다." << endl;
                                                                            cout << endl;
                                                                            sg.seat += to_string(sg.s_num);
                                                                            sg.seat += "번 ";
                                                                            sg.count++;
                                                                        }

                                                                        else
                                                                        {
                                                                            cout << "잘못된 입력입니다." << endl;
                                                                            cin.clear();
                                                                            cout << endl;
                                                                            cin.ignore(100,'\n');
                                                                        }
                                                                    } // while(sg.count == sg.p_num) // 인원 수 일치 체크

                                                                    cout << "고르신 좌석은 C열 " << sg.seat << "좌석입니다." << endl;
                                                                    cout << "가격은 " << pr.GOLD * sg.p_num << "원입니다." << endl;
                                                                    cout << endl;
                                                                    cout << "결제를 원하시면 1을, 돌아가시려면 0을 눌러주세요: ";
                                                                    cin >> sg.fin;

                                                                    if(sg.fin == 1)
                                                                    {
                                                                        system("clear");

                                                                        cout << "결제 완료!" << endl;
                                                                        cout << endl;
                                                                        cout << "결제하신 좌석은 C열 " << sg.seat << "좌석입니다." << endl;
                                                                        cout << "이용해주셔서 감사합니다!" << endl;
                                                                        cout << endl;

                                                                        sleep(5);
                                                                        ex.it++;

                                                                        cout << "엔터키를 누르면 돌아갑니다.";
                                                                        cin.get(eno.enter);
                                                                        cin.ignore(100,'\n');
                                                                        if(eno.enter == '\n')
                                                                        {   
                                                                            system("clear");
                                                                            break;
                                                                        }
                                                                    }
                                                                    
                                                                    else if(sg.fin == 0)
                                                                    {
                                                                        sg.p_num = 0;
                                                                        sg.s_num = 0;
                                                                        sg.count = 0;
                                                                        sg.seat.erase(0, 100);
                                                                        system("clear");
                                                                        break;
                                                                    }

                                                                    else
                                                                    {
                                                                        sg.p_num = 0;
                                                                        sg.s_num = 0;
                                                                        sg.count = 0;
                                                                        sg.seat.erase(0, 100);

                                                                        system("clear");
                                                                        cout << "잘못된 입력입니다. 구역 선택으로 돌아갑니다."<< endl;
                                                                        cin.clear();
                                                                        cout << endl;
                                                                        sleep(10);
                                                                        cin.ignore(100, '\n');
                                                                        break;
                                                                    }

                                                                } // if(sg.p_num > 0 && sg.p_num < 11) // 인원 수 오류 체크

                                                                else
                                                                {
                                                                    cout << "잘못된 입력입니다. 구역 선택으로 돌아갑니다."<< endl;
                                                                    cin.clear();
                                                                    cout << endl;
                                                                    sleep(2);
                                                                    cin.ignore(100, '\n');
                                                                    system("clear");
                                                                    break;
                                                                }

                                                            } // case '3': // GOLD - C열 선택 동안

                                                            case '4': // SILVER - D열 선택 동안
                                                            {
                                                                cout << "SILVER D열을 선택하셨습니다." << endl;
                                                                cout << endl;
                                                                ifstream lv_SILVER("txt_flie/lv_SILVER.txt");

                                                                if(!lv_SILVER.is_open())
                                                                {
                                                                    cout << "SILVER 구역을 불러올 수 없습니다." << endl;
                                                                }

                                                                while(lv_SILVER)
                                                                {
                                                                    getline(lv_SILVER, printf);
                                                                    cout << printf << endl;
                                                                }
                                                                lv_SILVER.close();
                                                                

                                                                cout << "인원 수를 입력하세요: ";
                                                                cin >> sg.p_num;
                                                                
                                                                if(sg.p_num > 0 && sg.p_num < 11) // 인원 수 오류 체크
                                                                {
                                                                    system("clear");
                                                                    ifstream lv_SILVER("txt_flie/lv_SILVER.txt");

                                                                    if(!lv_SILVER.is_open())
                                                                    {
                                                                        cout << "SILVER 구역을 불러올 수 없습니다." << endl;
                                                                    }

                                                                    while(lv_SILVER)
                                                                    {
                                                                        getline(lv_SILVER, printf);
                                                                        cout << printf << endl;
                                                                    }
                                                                    lv_SILVER.close();

                                                                    cout << "고르신 인원수는 " << sg.p_num << "명 입니다." << endl;
                                                                    cout << endl;
                                                                    

                                                                   while(sg.count != sg.p_num) // 인원 수 일치 체크
                                                                   {
                                                                        cout << "좌석 번호를 골라주세요: ";
                                                                        cin >> sg.s_num;
                                                                        
                                                                        if(sg.s_num > 0 && sg.s_num < 11)
                                                                        {
                                                                            cout << "고르신 좌석은 D열 " << sg.s_num << " 번좌석입니다." << endl;
                                                                            cout << endl;
                                                                            sg.seat += to_string(sg.s_num);
                                                                            sg.seat += "번 ";
                                                                            sg.count++;
                                                                        }

                                                                        else
                                                                        {
                                                                            cout << "잘못된 입력입니다." << endl;
                                                                            cin.clear();
                                                                            cout << endl;
                                                                            cin.ignore(100,'\n');
                                                                        }
                                                                    } // while(sg.count == sg.p_num) // 인원 수 일치 체크

                                                                    cout << "고르신 좌석은 D열 " << sg.seat << "좌석입니다." << endl;
                                                                    cout << "가격은 " << pr.SILVER * sg.p_num << "원입니다." << endl;
                                                                    cout << endl;
                                                                    cout << "결제를 원하시면 1을, 돌아가시려면 0을 눌러주세요: ";
                                                                    cin >> sg.fin;

                                                                    if(sg.fin == 1)
                                                                    {
                                                                        system("clear");

                                                                        cout << "결제 완료!" << endl;
                                                                        cout << endl;
                                                                        cout << "결제하신 좌석은 D열 " << sg.seat << "좌석입니다." << endl;
                                                                        cout << "이용해주셔서 감사합니다!" << endl;
                                                                        cout << endl;

                                                                        sleep(5);
                                                                        ex.it++;

                                                                        cout << "엔터키를 누르면 돌아갑니다.";
                                                                        cin.get(eno.enter);
                                                                        cin.ignore(100,'\n');
                                                                        if(eno.enter == '\n')
                                                                        {   
                                                                            system("clear");
                                                                            break;
                                                                        }
                                                                    }
                                                                    
                                                                    else if(sg.fin == 0)
                                                                    {
                                                                        sg.p_num = 0;
                                                                        sg.s_num = 0;
                                                                        sg.count = 0;
                                                                        sg.seat.erase(0, 100);
                                                                        system("clear");
                                                                        break;
                                                                    }

                                                                    else
                                                                    {
                                                                        sg.p_num = 0;
                                                                        sg.s_num = 0;
                                                                        sg.count = 0;
                                                                        sg.seat.erase(0, 100);

                                                                        system("clear");
                                                                        cout << "잘못된 입력입니다. 구역 선택으로 돌아갑니다."<< endl;
                                                                        cin.clear();
                                                                        cout << endl;
                                                                        sleep(10);
                                                                        cin.ignore(100, '\n');
                                                                        break;
                                                                    }

                                                                } // if(sg.p_num > 0 && sg.p_num < 11) // 인원 수 오류 체크

                                                                else
                                                                {
                                                                    cout << "잘못된 입력입니다. 구역 선택으로 돌아갑니다."<< endl;
                                                                    cin.clear();
                                                                    cout << endl;
                                                                    sleep(2);
                                                                    cin.ignore(100, '\n');
                                                                    system("clear");
                                                                    break;
                                                                }

                                                            } // case '4': // SILVER - D열 선택 동안

                                                            default:
                                                            {
                                                                cout << "옳지 않은 입력입니다." << endl;
                                                                sleep(1);
                                                                cin.ignore(100, '\n');
                                                                system("clear");
                                                                break;
                                                            } // switch(sc.num4)의 default

                                                        } // switch(sc.num4) // 구역 선택 동안

                                                    } // while(1) // 로그인 성공 동안

                                                    break;
                                                } // if(svd.id == fd.fid && svd.pw == fd.fpw) // 아이디&비밀번호 일치

                                            } // while(getline(user_check, svd.all)) // 로그인
                                            user_check.close();

                                            if(sg.judge == 0)
                                            {
                                                cout << "아이디나 로그인이 틀렸습니다." << endl;
                                                cout << "다시 시도하세요." << endl;
                                                sleep(2);
                                                system("clear");
                                                break;
                                            }

                                            break;
                                        } // while(1) // 3. 로그인 하는 동안

                                    } // case '3': // 3. 로그인

                                    default:
                                    {
                                        system("clear");
                                        break;
                                    } // switch(sc.num3)의 default

                                } // switch(sc.num3) // 로그인  메뉴 선택
 
                            } // while(sc.num2 == '2') // 로그인 동안

                        } // switch(sc.num2)의 case '2' // 로그인

                        default:
                        {
                            system("clear");
                            break;
                        } // switch(sc.num2)의 default
                    
                    } // switch(sc.num2) // 경기 예매 메뉴 선택

                } // while(sc.num1 == '4') // 경기 예매 동안

            } // switch(sc.num1)의 case '4' // 경기 예매

            default:
            {
                system("clear");
                break;
            } // switch(sc.num1)의 default

        } // switch(sc.num1) // 첫 메뉴 선택 후

    } // while(1) // 프로그램 선택 시작

    return 0;
} // int main()