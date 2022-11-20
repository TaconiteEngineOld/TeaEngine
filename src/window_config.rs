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
        self.title.to_string()
    }

    pub fn get_window_size(&self) -> Vec2 {
        Vec2::new(self.width as f32, self.height as f32)
    }
}
