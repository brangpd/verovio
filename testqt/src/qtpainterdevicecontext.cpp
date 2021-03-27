//
// Created by brangpd on 3/27/21.
//

#include "qtpainterdevicecontext.h"
#include "glyph.h"
#include <QGlyphRun>
#include <QRawFont>
#define FONT_SIZE 50.
#define mypos(x) (x / 512. * FONT_SIZE)
namespace vrv {
QtPainterDeviceContext::QtPainterDeviceContext(QPainter *qpainter) : m_painter(qpainter) {}
void QtPainterDeviceContext::SetBackground(int colour, int style) {}
void QtPainterDeviceContext::SetBackgroundImage(void *image, double opacity) {}
void QtPainterDeviceContext::SetBackgroundMode(int mode) {}
void QtPainterDeviceContext::SetTextForeground(int colour) {}
void QtPainterDeviceContext::SetTextBackground(int colour) {}
void QtPainterDeviceContext::SetLogicalOrigin(int x, int y)
{
    m_origin.x = x;
    m_origin.y = y;
}
Point QtPainterDeviceContext::GetLogicalOrigin()
{
    return m_origin;
}
void QtPainterDeviceContext::DrawSimpleBezierPath(Point *bezier) {}
void QtPainterDeviceContext::DrawComplexBezierPath(Point *bezier1, Point *bezier2) {}
void QtPainterDeviceContext::DrawCircle(int x, int y, int radius)
{
    DrawEllipse(x - radius, y - radius, 2 * radius, 2 * radius);
}
void QtPainterDeviceContext::DrawEllipse(int x, int y, int width, int height)
{
    GetPainter()->drawEllipse(x + width, y + height, width, height);
}
void QtPainterDeviceContext::DrawEllipticArc(int x, int y, int width, int height, double start, double end) {}
void QtPainterDeviceContext::DrawLine(int x1, int y1, int x2, int y2)
{
    GetPainter()->setPen(QPen(QBrush(Qt::black), ceil(FONT_SIZE / 30)));
    GetPainter()->drawLine(mypos(x1), mypos(y1), mypos(x2), mypos(y2));
}
void QtPainterDeviceContext::DrawPolygon(int n, Point *points, int xoffset, int yoffset, int fill_style)
{
    for (int i = 0; i < n; ++i) {
        const auto &pi = points[i];
    }
}
void QtPainterDeviceContext::DrawRectangle(int x, int y, int width, int height)
{
    GetPainter()->setPen(QPen(QBrush(Qt::black), ceil(FONT_SIZE / 30)));
    GetPainter()->drawRect((x - width) / FONT_SIZE, (y - height) / FONT_SIZE, width / FONT_SIZE, height / FONT_SIZE);
}
void QtPainterDeviceContext::DrawRotatedText(const std::string &text, int x, int y, double angle) {}
void QtPainterDeviceContext::DrawRoundedRectangle(int x, int y, int width, int height, int radius)
{
    GetPainter()->setPen(QPen(QBrush(Qt::black), ceil(FONT_SIZE / 30)));

    GetPainter()->drawRoundedRect(QRectF{ mypos(x), mypos(y), mypos(width), mypos(height) }, mypos(radius), mypos(radius));
}
void QtPainterDeviceContext::DrawText(
    const std::string &text, const std::wstring wtext, int x, int y, int width, int height)
{
}
void QtPainterDeviceContext::DrawMusicText(const std::wstring &text, int x, int y, bool setSmuflGlyph)
{
    assert(m_fontStack.top());

    static int i = 0;
    QFont oldFont(GetPainter()->font());
    QFont bravura("Bravura", FONT_SIZE);
    GetPainter()->setFont(bravura);
    GetPainter()->setPen(QPen(QColor(Qt::black)));
    for (auto c : text) {
        if (auto glyph = Resources::GetGlyph(c)) {
            float xx, yy;
            xx = x, yy = y;
            if (m_fontStack.top()->GetWidthToHeightRatio() != 1.0f) {
                auto aa = m_fontStack.top()->GetWidthToHeightRatio();
                auto ee = x * (1. - m_fontStack.top()->GetWidthToHeightRatio());
                xx = aa * xx + ee;
                yy = yy + ee;
            }

            if (glyph->GetHorizAdvX() > 0) {
                x += mypos(glyph->GetHorizAdvX());
            }
            else {
                int gx, gy, gw, gh;
                glyph->GetBoundingBox(gx, gy, gw, gh);
                x += mypos(gw);
            }

            GetPainter()->drawText(QPointF(mypos(xx), mypos(yy)), QString(c));
        }
    }
    GetPainter()->setFont(oldFont);
    return;
}
void QtPainterDeviceContext::DrawSpline(int n, Point *points) {}
void QtPainterDeviceContext::DrawSvgShape(int x, int y, int width, int height, pugi::xml_node svg) {}
void QtPainterDeviceContext::DrawBackgroundImage(int x, int y) {}
void QtPainterDeviceContext::StartText(int x, int y, data_HORIZONTALALIGNMENT alignment) {}
void QtPainterDeviceContext::EndText() {}
void QtPainterDeviceContext::MoveTextTo(int x, int y, data_HORIZONTALALIGNMENT alignment) {}
void QtPainterDeviceContext::MoveTextVerticallyTo(int y) {}
void QtPainterDeviceContext::StartGraphic(
    Object *object, std::string gClass, std::string gId, bool primary, bool preprend)
{
}
void QtPainterDeviceContext::EndGraphic(Object *object, View *view) {}
void QtPainterDeviceContext::ResumeGraphic(Object *object, std::string gId) {}
void QtPainterDeviceContext::EndResumedGraphic(Object *object, View *view) {}
void QtPainterDeviceContext::RotateGraphic(const Point &orig, double angle) {}
void QtPainterDeviceContext::StartPage() {}
void QtPainterDeviceContext::EndPage() {}
ClassId QtPainterDeviceContext::GetClassId() const
{
    return CUSTOM_DEVICE_CONTEXT;
}
} // namespace vrv
