#ifndef COOKIE_H
#define COOKIE_H
#include "common.hpp"
#include <boost/regex.hpp>

namespace echttp {

class Cookie
{
public:

    // 定义option_item类型.
    typedef std::pair<std::string, std::string> option_item;
    // 定义option_item_list类型.
    typedef std::vector<option_item> option_item_list;
    // for boost::assign::insert
    typedef option_item value_type;

    Cookie();

    // 添加选项, 由 key/value形式添加.
    void Insert(const std::string& key, const std::string& val);

    // 添加选项，由 std::part 形式.
    void Insert(value_type& item);

    // 删除选项.
    cookie& Remove(const std::string& key);

    // 查找指定key的value.
    bool Find(const std::string& key, std::string& val);

    // 查找指定的 key 的 value. 没找到返回 ""，　这是个偷懒的帮助.
    std::string Find(const std::string& key);

    // 得到cookie字符串.
    std::string CookieString();

    //从header字符串正则替换cookie
    void ParseHeader(const std::string &header);

    // 清空.
    void clear();

    // 返回所有option.
    option_item_list& OptionAll();

    // 返回当前option个数.
    int Size() const;

protected:
    option_item_list m_opts;

};

}


#endif // COOKIE_H
