use glam::Vec2;

pub struct WindowConfig {
    pub title: String,
    pub width: i32,
    pub height: i32,
    pub fullscreen: bool,
}

impl WindowConfig {
    pub fn is_fullscreen(&self) -> bool {
        self.fullscreen
    }

    pub fn get_window_title(&self) -> String {
        self.title
    }

    pub fn get_window_size(&self) -> Vec2 {
        Vec2::new(self.width, self.height)
    }
}
