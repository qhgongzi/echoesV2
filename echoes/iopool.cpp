#include "iopool.h"

echttp::Iopool* echttp::Iopool::pool=NULL;

echttp::iopool::~iopool()
{
    io.stop();
}


echttp::Iopool *echttp::Iopool::Instance(int thread_num)
{
    if (NULL==pool)
    {
        pool=new Iopool(thread_num);
    }
    return pool;
}

void echttp::Iopool::Stop()
{
    io.stop();
}

echttp::Iopool::Iopool(int thread_num)
    :work(io)
{
    for(int i=0;i<thread_num;++i)
    {
        workers.create_thread(boost::bind(&boost::asio::io_service::run,&io));
    }

}
