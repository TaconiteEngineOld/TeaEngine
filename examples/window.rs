use teaengine::*;

fn main() {
    TeaEngine::build(WindowConfig {
        title: "TeaEngine".to_string(),
        width: 640,
        height: 480,
        fullscreen: false,
    })
    .run();
}
