#ifndef IOPOOL_H
#define IOPOOL_H
#include <boost/asio.hpp>
#include <boost/thread.hpp>

namespace echttp
{

class iopool
{
public:
    static iopool* Instance(int thread_num);
    void Stop(void);

    boost::asio::io_service io;

private:
    iopool(int thread_num);
    ~iopool();

    boost::asio::io_service::work work;
    boost::thread_group workers;

protected:
    static iopool * pool;

};


}

#endif // IOPOOL_H
