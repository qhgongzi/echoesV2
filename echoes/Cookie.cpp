#include "cookie.h"

echttp::Cookie::Cookie()
{

}



void echttp::Cookie::Insert(const std::string &key, const std::string &val)
{
    remove(key);
    m_opts.push_back(option_item(key, val));
}

void echttp::Cookie::Insert(echttp::cookie::value_type &item)
{
    remove(item.first);
    m_opts.push_back(item);
}

echttp::Cookie &echttp::cookie::Remove(const std::string &key)
{
    for (option_item_list::iterator i = m_opts.begin(); i != m_opts.end(); i++)
    {
        if (i->first == key)
        {
            m_opts.erase(i);
            return *this;
        }
    }
    return *this;
}

bool echttp::Cookie::Find(const std::string &key, std::string &val)
{
    std::string s = key;
    boost::to_lower(s);
    for (option_item_list::const_iterator f = m_opts.begin(); f != m_opts.end(); f++)
    {
        std::string temp = f->first;
        boost::to_lower(temp);
        if (temp == s)
        {
            val = f->second;
            return true;
        }
    }
    return false;
}

std::string echttp::Cookie::Find(const std::string &key)
{
    std::string v;
    find(key,v);
    return v;
}

std::string echttp::Cookie::CookieString()
{
    std::string str;
    for (option_item_list::const_iterator f = m_opts.begin(); f != m_opts.end(); f++)
    {
        str += (f->first + "=" + f->second + "; ");
    }
    return str;
}

void echttp::Cookie::ParseHeader(const std::string &header)
{
    boost::smatch result;
    std::string regtxt("Set-Cooki.*? (.*?)=(.*?);");
    boost::regex rx(regtxt);

    std::string::const_iterator it=header.begin();
    std::string::const_iterator end=header.end();

    while (regex_search(it,end,result,rx))
    {
        std::string cookie_key=result[1];
        std::string cookie_value=result[2];

        this->remove(cookie_key);
        this->insert(cookie_key,cookie_value);

        it=result[0].second;
    }
}

void echttp::Cookie::clear()
{
    m_opts.clear();
}

echttp::cookie::option_item_list &echttp::Cookie::OptionAll()
{
    return m_opts;
}

int echttp::cookie::Size() const
{
    return m_opts.size();
}
