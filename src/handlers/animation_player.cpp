#include "animation_player.h"


handlers::AnimationPlayer::AnimationPlayer(type::Position* position, Texture2D* texture, int textureColumns, int textureRows, int textureWidth, int textureHeight,
    int* wantedSpeed, type::Position textureOffset, type::Vec_Int framesPerRow)
    : _position(position), _texture(texture), _textureColumns(textureColumns), _textureRows(textureRows),
    _textureWidth(textureWidth), _textureHeight(textureHeight), _wantedSpeed(wantedSpeed), _textureOffset(textureOffset), _framesPerRow(framesPerRow)
{
    std::cout << "Animation player created!" << std::endl;
}


handlers::AnimationPlayer::~AnimationPlayer()
{
    std::cout << "Animation player deleted!" << std::endl;
}


// When we input a new animation:
void handlers::AnimationPlayer::SetCurrentAnimation(int animation) {
    _currentAnimation = animation;
    _currentFrame = 0;
    _isAnimationOver = false;
}


bool handlers::AnimationPlayer::GetIsAnimationOver() {
    return _isAnimationOver;
}


void handlers::AnimationPlayer::SetIsObjectScareCrow(bool isObjectScarecrow)
{
    _isObjectScarecrow = isObjectScarecrow;
}


void handlers::AnimationPlayer::MakeTransparent() {
    _color = { 255, 255, 255, 150 };
}


void handlers::AnimationPlayer::MakeUntransparent() {
    _color = { 255, 255, 255, 255 };
}


void handlers::AnimationPlayer::Animate()
{
    // If animation has begun or is not over yet
    // Or current animation is of type idle
    if (_isAnimationOver == false
        || _currentAnimation == eIdleUp
        || _currentAnimation == eIdleDown
        || _currentAnimation == eIdleRight
        || _currentAnimation == eIdleLeft
        || _currentAnimation == eWalkUp
        || _currentAnimation == eWalkDown
        || _currentAnimation == eWalkRight
        || _currentAnimation == eWalkLeft)
    {

        // If the current frame is smaller than the last frame of the row (row starts at 1 and current frame at 0):
        // Draw rectangle of texture dependant of current animation and frame
        // Draws the same frame as long as we haven't reached wanted speed
        if (_currentFrame < _framesPerRow[_currentAnimation])
        {

            DrawTextureRec(*_texture,
                { static_cast<float>(_textureWidth) / _textureColumns * _currentFrame,
                static_cast<float>(_textureHeight) / _textureRows * _currentAnimation,
                static_cast<float>(_textureWidth) / _textureColumns,
                static_cast<float>(_textureHeight) / _textureRows },
                { static_cast<float>(_position->first * game::TILE_SIZE) - _textureOffset.first,
                static_cast<float>(_position->second * game::TILE_SIZE) - _textureOffset.second },
                _color);

            // Once specific number of updates have happened:
            // Reset speed iterator and show next frame
            if (_speedIterator >= *_wantedSpeed)
            {
                _currentFrame++;
                _speedIterator = 0;
            }
            else
                _speedIterator += GetFrameTime() * _standartSpeed;
        }


        // When specific frames of following animations have been played, make the animation cancable
        if (_currentFrame > _numberOfFramesToNotCancel
            && (_currentAnimation == eWalkUp
                || _currentAnimation == eWalkDown
                || _currentAnimation == eWalkRight
                || _currentAnimation == eWalkLeft))
        {
            _isAnimationOver = true;
        }


        if (_currentFrame == _framesPerRow[_currentAnimation]
            && _isObjectScarecrow
            && (_currentAnimation == eDeath1)
            || _currentAnimation == eDeath2)
        {
            _isAnimationOver = false;
            _currentFrame--;
        }


        // If a full animation hast been played it will switch to the dependant idle animation
        // Idle animations are also cancable but without the need of playing specific frames first
        if (_currentFrame == _framesPerRow[_currentAnimation])
        {
            if (_currentAnimation == eAttackUp
                || _currentAnimation == eAttackUp2
                || _currentAnimation == eAttackUp3
                || _currentAnimation == eWalkUp)
            {
                _currentAnimation = eIdleUp;
            }
            if (_currentAnimation == eAttackDown
                || _currentAnimation == eAttackDown2
                || _currentAnimation == eAttackDown3
                || _currentAnimation == eWalkDown)
            {
                _currentAnimation = eIdleDown;
            }
            if (_currentAnimation == eAttackRight
                || _currentAnimation == eAttackRight2
                || _currentAnimation == eAttackRight3
                || _currentAnimation == eWalkRight)
            {
                _currentAnimation = eIdleRight;
            }
            if (_currentAnimation == eAttackLeft
                || _currentAnimation == eAttackLeft2
                || _currentAnimation == eAttackLeft3
                || _currentAnimation == eWalkLeft)
            {
                _currentAnimation = eIdleLeft;
            }

            _currentFrame = 0;
            _isAnimationOver = true;
        }
    }
}
