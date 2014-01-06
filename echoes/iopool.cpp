#include "iopool.h"

echttp::iopool* echttp::iopool::pool=NULL;

echttp::iopool::~iopool()
{
    io.stop();
}


echttp::iopool *echttp::iopool::Instance(int thread_num)
{
    if (NULL==pool)
    {
        pool=new iopool(thread_num);
    }
    return pool;
}

void echttp::iopool::Stop()
{
    io.stop();
}

echttp::iopool::iopool(int thread_num)
    :work(io)
{
    for(int i=0;i<thread_num;++i)
    {
        workers.create_thread(boost::bind(&boost::asio::io_service::run,&io));
    }

}
