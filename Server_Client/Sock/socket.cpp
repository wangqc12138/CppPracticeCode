#include "socket.h"
int Close(int fd){
    int ret=close(fd);
    if(-1==ret){
        perror("close fd error!");
        return -1;
    }
    return 0;
}
int Socket::Connect(const string strFilename){
    int family=AF_UNIX;
    if(m_iHandle!=-1){
        Close(m_iHandle);
    }
    m_iHandle=socket(family,SOCK_STREAM,0);
    if(-1==m_iHandle){
        perror("create socket error!");
        return -1;
    }
    sockaddr_un sa;
    sa.sun_family=family;
    strcpy(sa.sun_path,strFilename.c_str());
    int ret=connect(m_iHandle,(const struct sockaddr*)&sa,sizeof(sa));
    if(ret==-1){
        perror("connet error!");
        return -1;
    }
    return 0;
}
int Socket::Connect(const string strIp,const int iPort){
    int ret,family=AF_INET;
    if(strIp.find(':')!=string::npos){
        family=AF_INET6;
    }
    if(m_iHandle!=-1){
        Close(m_iHandle);
    }
    m_iHandle=socket(family,SOCK_STREAM,0);
    if(-1==m_iHandle){
        perror("create socket error!");
        return -1;
    }
    //int connect(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
    sockaddr_in sa;
    sa.sin_family=family;
    sa.sin_port=htons(iPort);
    inet_pton(family,strIp.c_str(),&sa.sin_addr.s_addr);
    ret=connect(m_iHandle,(const struct sockaddr*)&sa,sizeof(sa));
    if(ret==-1){
        perror("connet error!");
        return -1;
    }
    return 0;
}
int Socket::Listen(const string strFilename){
    unlink(strFilename.c_str());
    int ret,family=AF_UNIX;
    if(m_iHandle!=-1){
        Close(m_iHandle);
    }
    m_iHandle=socket(family,SOCK_STREAM,0);
    if(-1==m_iHandle){
        perror("create socket error!");
        return -1;
    }
    sockaddr_un sa;
    sa.sun_family=family;
    //需要文件
    strcpy(sa.sun_path,strFilename.c_str());
    ret=bind(m_iHandle,(struct sockaddr*) &sa,sizeof(struct sockaddr_un));
    if(-1==ret){
        perror("sock bind error!");
        return -1;
    }
    //int listen(int sockfd, int backlog);
    ret=listen(m_iHandle,10);
    if(-1==ret){
        perror("sock listen error!");
        return -1;
    }
    return m_iHandle;
}
int Socket::Listen(const string strIp,const int iPort){
    int ret,family=AF_INET;
    if(strIp.find(':')!=string::npos){
        m_iFamily=AF_INET6;
        family=AF_INET6;
    }
    //int socket(int domain, int type, int protocol);
    if(m_iHandle!=-1){
        Close(m_iHandle);
    }
    m_iHandle=socket(family,SOCK_STREAM,0);
    if(-1==m_iHandle){
        perror("create socket error!");
        return -1;
    }
    int opt =1;
    (m_iHandle,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt));
    //int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
    sockaddr_in sa;
    sa.sin_family=family;
    sa.sin_port=htons(iPort);
    //int inet_pton(int af, const char *src, void *dst);
    inet_pton(family,strIp.c_str(),&sa.sin_addr.s_addr);
    ret=bind(m_iHandle,(const struct sockaddr*) &sa,sizeof(sa));
    if(-1==ret){
        perror("sock bind error!");
        return -1;
    }
    //int listen(int sockfd, int backlog);
    ret=listen(m_iHandle,10);
    if(-1==ret){
        perror("sock listen error!");
        return -1;
    }
    return m_iHandle;
}
int Socket::Accept_Local(){
    int ret;
    sockaddr_un c_sa;
    int iLen=sizeof(c_sa);
    ret=accept(m_iHandle,(struct sockaddr*) &c_sa,(socklen_t *)&iLen);
    if(-1==ret){
        perror("accept error!");
        return -1;
    }
    printf("file path is %s\n",c_sa.sun_path);
    return ret;
}
int Socket::Accept(){
    int ret;
    // int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    struct sockaddr_in c_sa;
    int salen=sizeof(c_sa);
    ret=accept(m_iHandle,(struct sockaddr*) &c_sa,(socklen_t *)&salen);
    if(-1==ret){
        perror("accept error!");
        return -1;
    }
    char cip[50];
    int cport;
    inet_ntop(m_iFamily,&c_sa.sin_addr.s_addr,cip,salen);
    cport=ntohs(c_sa.sin_port);
    printf("client ip is %s,port is %d\n",cip,cport);
    return ret;
}
int Read(int fd,char* buf,int len){
	int ret=read(fd,buf,len);
    cout<<ret<<endl;
	if(ret<0){
		char buf[BUFSIZ];
		snprintf(buf,BUFSIZ,"read %d error!",fd);
		perror(buf);
	}
	return ret;
}
int Write(int fd,char* buf,int len){
	int ret=write(fd,buf,len);
	if(ret<0){
		char buf[BUFSIZ];
		snprintf(buf,BUFSIZ,"write %d error!",fd);
		perror(buf);
	}
	return ret;
}