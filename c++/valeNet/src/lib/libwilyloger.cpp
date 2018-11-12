//
// Created by edmond on 18-10-27.
//

#include <cstring>
#include "../include/libwilyloger.h"

/**
 * 日志等级的输出流，默认状态下为标注输入输出设备，可以在初始化时调整为文件流
 */
std::ofstream wily::VLoger::m_error_log_file;
std::ofstream wily::VLoger::m_info_log_file;
std::ofstream wily::VLoger::m_warn_log_file;

/**
 * 初始化loger，分别传入需要保存的文件的路径，将标准输出流调整为对应的文件流
 * @param info_log_filename
 * @param warn_log_filename
 * @param error_log_filename
 */
void wily::initLogger(const std::string&info_log_filename,
                const std::string&warn_log_filename,
                const std::string&error_log_filename){
    wily::VLoger::m_info_log_file.open(info_log_filename.c_str());
    wily::VLoger::m_warn_log_file.open(warn_log_filename.c_str());
    wily::VLoger::m_error_log_file.open(error_log_filename.c_str());
}

/**
 * 获取流
 * @param log_rank
 * @return
 */
std::ostream& wily::VLoger::getStream(log_rank_t log_rank){
    return (INFO == log_rank) ?
           (m_info_log_file.is_open() ?m_info_log_file : std::cout) :
           (WARNING == log_rank ?
            (m_warn_log_file.is_open()? m_warn_log_file : std::cerr) :
            (m_error_log_file.is_open()? m_error_log_file : std::cerr));
}

/**
 * 进行输出
 * @param log_rank
 * @param line
 * @param function
 * @return
 */
std::ostream& wily::VLoger::start(log_rank_t log_rank,
                            int line,
                            const std::string& function) {
    time_t tm;
    time(&tm);
    char* time_string;
    time_string = ctime(&tm);
    char dest[128];
    strncpy(dest, time_string, strlen(time_string)-1);
    dest[strlen(time_string)-1]='\0';
    return getStream(log_rank) << dest<<" "
                               << function <<"["
                               << line <<"]:"
                               <<std::flush;
}

/**
 * 析构器
 */
wily::VLoger::~VLoger(){
    getStream(m_log_rank) << std::endl << std::flush;

    if (FATAL == m_log_rank) {
        m_info_log_file.close();
        m_info_log_file.close();
        m_info_log_file.close();
        abort();
    }
}
