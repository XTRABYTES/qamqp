#ifndef amqp_client_p_h__
#define amqp_client_p_h__

#include <QSharedPointer>

#include "amqp_network.h"
#include "amqp_connection.h"
#include "amqp_authenticator.h"

namespace QAMQP
{

class Queue;
class Exchange;
class ClientPrivate
{
public:
    ClientPrivate(Client *q);
    ~ClientPrivate();

    void init(const QUrl &connectionString = QUrl());
    void connect();
    void disconnect();
    void parseConnectionString(const QUrl &connectionString);
    void sockConnect();

    quint32 port;
    QString host;
    QString virtualHost;

    QPointer<Network> network_;
    QPointer<Connection> connection_;
    QSharedPointer<Authenticator> auth_;

    bool isSSl() const;

    Client * const q_ptr;
    Q_DECLARE_PUBLIC(Client)

};

} // namespace QAMQP

#endif // amqp_client_p_h__