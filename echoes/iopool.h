#ifndef IOPOOL_H
#define IOPOOL_H
#include <boost/asio.hpp>
#include <boost/thread.hpp>

namespace echttp
{

class Iopool
{
public:
    static Iopool* Instance(int thread_num);
    void Stop(void);

    boost::asio::io_service io;

private:
    Iopool(int thread_num);
    ~iopool();

    boost::asio::io_service::work work;
    boost::thread_group workers;

protected:
    static Iopool * pool;

};


}

#endif // IOPOOL_H
