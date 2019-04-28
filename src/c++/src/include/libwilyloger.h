//
// Created by edmond on 18-10-27.
//

#ifndef WILY_VLOG_H
#define WILY_VLOG_H

#include <string>
#include <fstream>
#include <iostream>



namespace wily {
    typedef enum log_rank {
        INFO,
        WARNING,
        ERROR,
        FATAL
    } log_rank_t;

    class VLoger {
        friend void initLogger(const std::string &info_log_filename, const std::string &warn_log_filename,
                               const std::string &erro_log_filename);

    public:
        //构造函数
        explicit VLoger(log_rank_t log_rank) : m_log_rank(log_rank) {};

        ~VLoger();

        static std::ostream& start(log_rank_t log_rank,
                                   int line,
                                   const std::string &function);

    private:

        static std::ostream &getStream(log_rank_t log_rank);

        static std::ofstream m_info_log_file;
        static std::ofstream m_warn_log_file;
        static std::ofstream m_error_log_file;
        log_rank_t m_log_rank;
    };
}

#define LOG(log_rank)\
VLoger(log_rank).start(log_rank, __LINE__,__FUNCTION__)


#endif //WILY_VLOG_H

