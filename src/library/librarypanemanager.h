#ifndef LIBRARYVIEWMANAGER_H
#define LIBRARYVIEWMANAGER_H

#include <QObject>
#include <QWidget>
#include <QStackedWidget>

#include "library/libraryfeature.h"
#include "widget/wbuttonbar.h"
#include "widget/wlibrary.h"
#include "widget/wsearchlineedit.h"

class LibraryPaneManager : public QObject {
    Q_OBJECT

  public:

    const int RIGHT_PANE_COUNT = 2;

    LibraryPaneManager(QObject* parent = nullptr);
    
    ~LibraryPaneManager();
    
    bool initialize();

    // All features must be added before adding a pane
    void bindSidebarExpanded(WLibrary* leftWidget, KeyboardEventFilter *pKeyboard);
    void bindLibraryWidget(WLibrary* rightWidget, KeyboardEventFilter *pKeyboard);
    
    inline WLibrary* getLeftPane() { return m_pSidebarExpanded; }
    inline WLibrary* getRightPane() { return m_pLibraryWidget; }

    void addFeature(LibraryFeature* feature);

  public slots:

    void search(QString& text);
    

  private:

    WLibrary* m_pSidebarExpanded;
    WLibrary* m_pLibraryWidget;
    
    QVector<LibraryFeature*> m_features;
    
    QVector<int> m_currentFeature;
    int m_currentPane;

  private slots:

    // Used to handle focus change
    // TODO(jmigual): Still needs to be implemented
    bool eventFilter(QObject* object, QEvent* event);
};

#endif // LIBRARYVIEWMANAGER_H