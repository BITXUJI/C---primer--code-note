#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <memory>
#include <sstream>
class QueryResult;
using line_no = std::vector<std::string>::size_type;

class TextQuery
{
public:
    TextQuery(std::ifstream &);
    QueryResult query(const std::string &) const;

private:
    std::shared_ptr<std::vector<std::string>> file;
    std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

TextQuery::TextQuery(std::ifstream &is) : file(new std::vector<std::string>)
{
    std::string text;
    while (std::getline(is, text))
    {
        file->push_back(text);
        int n = file->size() - 1;
        std::istringstream line(text);
        std::string word;
        while (line >> word)
        {
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new std::set<line_no>);
            lines->insert(n);
        }
    }
}
class QueryResult
{
    friend std::ostream &print(std::ostream &,const QueryResult&);
public:
    QueryResult(std::string s,std::shared_ptr<std::set<line_no>> p,std::shared_ptr<std::vector<std::string>> f):sought(s),lines(p),file(f){}
private:
    std::string sought;
    std::shared_ptr<std::set<line_no>> lines;
    std::shared_ptr<std::vector<std::string>> file;
};
QueryResult TextQuery::query(const std::string &sought) const{
static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
auto loc =wm.find(sought);
if(loc==wm.end())
    return QueryResult(sought,nodata,file);
else
    return QueryResult(sought,loc->second,file);
}
std::string make_plural(std::size_t i, const std::string&word,const std::string &end){
    return (i>1)?word+end:word;
}
std::ostream &print(std::ostream &os,const QueryResult &qr){
    os<<qr.sought<<" occors "<<qr.lines->size()<<" "<< make_plural(qr.lines->size(),"time","s")<<std::endl;
    for(auto num: *qr.lines)
        os<<"\t(line"<<num+1<<")"<<*(qr.file->begin()+num)<<std::endl;
    return os;
}

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        std::cout << "enter word to look for, or q to quit";
        std::string s;
        if (!(std::cin >> s) || s == "q")
            break;
        print(std::cout, tq.query(s)) << std::endl;
    }
}

int main(){
    std::ifstream filename("word_result");
    runQueries(filename);

}