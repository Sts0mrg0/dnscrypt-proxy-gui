#include "resolver_entries.h"

ResolverEntries::ResolverEntries(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle("Resolver Entries");

    entries = new QListWidget(this);
    connect(entries, SIGNAL(entered(QModelIndex)),
            this, SLOT(done(int)));
    ok = new QPushButton("Ok", this);

    commonLayout = new QVBoxLayout(this);
    commonLayout->addWidget(entries);
    commonLayout->addWidget(ok, 0, Qt::AlignCenter);
    setLayout(commonLayout);
}

QString ResolverEntries::getEntry() const
{
    QString ret;
    QListWidgetItem *item = entries->currentItem();
    if ( item!=nullptr ) {
        ret = item->text();
    };
    return ret;
}
void ResolverEntries::setEntries(const QStringList _entries)
{
    entries->addItems(_entries);
}
