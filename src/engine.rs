use crate::window_config::*;
use miniquad::{EventHandler, Context, conf};

pub struct TeaEngine {
    window_config: WindowConfig,
}

struct Stage {}

impl EventHandler for Stage {
    fn update(&mut self, _ctx: &mut Context) {}

    fn draw(&mut self, ctx: &mut Context) {
        ctx.clear(Some((0.18, 0.20, 0.25, 1.0)), None, None);
    }
}

impl TeaEngine {
    pub fn build(config: WindowConfig) -> TeaEngine {
        return TeaEngine { window_config: config };
    }

    pub fn run(&self) {
        miniquad::start(
            conf::Conf {
                window_title: self.window_config.get_window_title(),
                window_width: self.window_config.get_window_size().x as i32,
                window_height: self.window_config.get_window_size().y as i32,
                fullscreen: self.window_config.is_fullscreen(),
                ..Default::default()
            },
            |_ctx| Box::new(Stage {}),
        );
    }
}
