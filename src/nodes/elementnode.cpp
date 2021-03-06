#include "elementnode.h"
#include <QStringList>

ElementNode::ElementNode(const QString tagName,
                         const AttributesMap attrs,
                         const NodeVector children):
    Node(Element, children),
    m_tagName(tagName),
    m_attrs(attrs)
{


}

ElementNode::~ElementNode()
{

}

QString ElementNode::toString(){
    return m_tagName;
}


QSharedPointer<ElementNode> ElementNode::getElementById(QString id){
//    if(m_nodetype == Node::Element){
//        QString myid = m_attrs.value("id");
//        if( myid.isSimpleText() && myid == id){
//            return sharedFromThis();
//        }
//    }
    QSharedPointer<ElementNode> result;
//    for(auto& child: m_children){
//        result = child->getElementById();
//    }
    return result;
}

QList<QSharedPointer<ElementNode> > ElementNode::getElementsByClassName(QStringList className){
    QString target = className.first();
    QList<QSharedPointer<ElementNode> > result;
//    QString myclass = m_attrs.value("class");
//    if(myclass.isSimpleText() && myclass == target) {
//        if( className.size()== 1){
//            return sharedFromThis();
//        } else {
//            for(aut& child: children){
//                result = child->getElementsByClassName(className.removeFirst(););
//            }
//        }
//    } else {
//        for(auto& child: children){
//            result = child->getElementsByClassName(className);
//        }
//    }
    return result;
}
