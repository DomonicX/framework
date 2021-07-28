#ifndef ILAYER_H
#define ILAYER_H


class Level;
class ILayer
{
public:
    ILayer();
    virtual ~ILayer();
    virtual void Render() = 0;
    virtual void Update(Level* pLevel)= 0;
protected:

private:
};

#endif // ILAYER_H
